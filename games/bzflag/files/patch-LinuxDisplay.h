--- src/platform/LinuxDisplay.h.orig	Tue Mar 27 14:54:59 2001
+++ src/platform/LinuxDisplay.h	Tue Mar 27 14:55:06 2001
@@ -18,7 +18,7 @@
 #define	BZF_LINUXDISPLAY_H
 
 #include "XDisplay.h"
-#if defined(__linux__) && defined(XF86VIDMODE_EXT)
+#if defined(XF86VIDMODE_EXT)
 #define USE_XF86VIDMODE_EXT
 #define private c_private
 #include <X11/extensions/xf86vmode.h>
