
$FreeBSD$

--- src/video/vgl/SDL_vglmouse_c.h.orig	Wed Jan 24 00:51:13 2001
+++ src/video/vgl/SDL_vglmouse_c.h	Wed Jan 24 00:51:13 2001
@@ -0,0 +1,36 @@
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
+ "@(#) $Id: SDL_vglmouse_c.h,v 1.2.2.1 2000/03/16 15:20:39 hercules Exp $";
+#endif
+
+#include "SDL_vglvideo.h"
+
+/* Functions to be exported */
+extern void VGL_FreeWMCursor(_THIS, WMcursor *cursor);
+extern WMcursor *VGL_CreateWMCursor(_THIS,
+		Uint8 *data, Uint8 *mask, int w, int h, int hot_x, int hot_y);
+extern int VGL_ShowWMCursor(_THIS, WMcursor *cursor);
+extern void VGL_WarpWMCursor(_THIS, Uint16 x, Uint16 y);
+
