
$FreeBSD$

--- src/video/vgl/SDL_vglvideo.h.orig	Sat Jan 27 17:25:12 2001
+++ src/video/vgl/SDL_vglvideo.h	Sat Jan 27 17:30:56 2001
@@ -0,0 +1,69 @@
+/*
+    SDL - Simple DirectMedia Layer
+    Copyright (C) 1997, 1998, 1999, 2000  Sam Lantinga
+
+    This library is free software; you can redistribute it and/or
+    modify it under the terms of the GNU Library General Public
+    License as published by the Free Software Foundation; either
+    version 2 of the License, or (at your option) any later version.
+
+    This library is distributed in the hope that it will be useful,
+    but WITHOUT ANY WARRANTY; without even the implied warranty of
+    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+    Library General Public License for more details.
+
+    You should have received a copy of the GNU Library General Public
+    License along with this library; if not, write to the Free
+    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+
+    Sam Lantinga
+    slouken@devolution.com
+*/
+
+#ifdef SAVE_RCSID
+static char rcsid =
+ "@(#) $Id: SDL_vglvideo.h,v 1.3.2.1 2000/03/16 15:20:39 hercules Exp $";
+#endif
+
+#ifndef _SDL_vglvideo_h
+#define _SDL_vglvideo_h
+
+#include <sys/fbio.h>
+#include <sys/consio.h>
+#include <vgl.h>
+
+#include "SDL_mouse.h"
+#include "SDL_mutex.h"
+#include "SDL_sysvideo.h"
+
+/* Hidden "this" pointer for the video functions */
+#define _THIS	SDL_VideoDevice *this
+
+typedef struct {
+	int ModeId;
+	int Depth;
+	int Rmask;
+	int Gmask;
+	int Bmask;
+	VGLBitmap ModeInfo;
+} VGLMode;
+
+/* Private display data */
+struct SDL_PrivateVideoData {
+#define NUM_MODELISTS	4		/* 8, 16, 24, and 32 bits-per-pixel */
+	int SDL_nummodes[NUM_MODELISTS];
+	SDL_Rect **SDL_modelist[NUM_MODELISTS];
+	SDL_mutex *hw_lock;
+	VGLMode *VGLCurMode;
+	int flip_page;
+	byte *flip_address[2];
+};
+/* Old variable names */
+#define SDL_nummodes	(this->hidden->SDL_nummodes)
+#define SDL_modelist	(this->hidden->SDL_modelist)
+#define hw_lock		(this->hidden->hw_lock)
+#define VGLCurMode	(this->hidden->VGLCurMode)
+#define flip_page	(this->hidden->flip_page)
+#define flip_address	(this->hidden->flip_address)
+
+#endif /* _SDL_vglvideo_h */
