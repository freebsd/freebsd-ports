--- ./linux/x11_linux.h.orig	Tue May 23 20:05:59 2006
+++ ./linux/x11_linux.h	Tue May 23 20:06:00 2006
@@ -1,6 +1,6 @@
-#ifndef __linux__
+#ifndef __unix__
 #  error You should not be including this file on this platform
-#endif // __linux__
+#endif // __unix__
 
 #ifndef __X11_LINUX_H__
 #define __X11_LINUX_H__
