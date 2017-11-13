/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2017 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#ifndef _OgreTextureGpuListener_H_
#define _OgreTextureGpuListener_H_

#include "OgrePrerequisites.h"
#include "OgreHeaderPrefix.h"

namespace Ogre
{
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup Resources
    *  @{
    */

    class _OgreExport TextureGpuListener
    {
	public:
        enum Reason
        {
            Unknown,
            FromStorageToSysRam,
            GainedResidency,
            LostResidency,
            PoolTextureSlotChanged,
            /// This Reason is called when TextureGpu::notifyDataIsReady is called.
            /// This normally means worker thread is done loading texture from file
            /// and uploading it to GPU; and can now be used for rendering.
            /// It does NOT mean that Ogre has finished issueing rendering commands to
            /// a RenderTexture and is now ready to be presented to the monitor.
            ReadyForRendering,
            Deleted
        };

		/// Called when a TextureGpu changed in a way that affects how it is displayed:
		///		1. TextureGpu::notifyDataIsReady got called (texture is ready to be displayed)
		///		2. Texture changed residency status.
        ///     3. Texture is being deleted. It won't be a valid pointer after this call.
        virtual void notifyTextureChanged( TextureGpu *texture, TextureGpuListener::Reason reason ) = 0;
    };

    /** @} */
    /** @} */
}

#include "OgreHeaderSuffix.h"

#endif
