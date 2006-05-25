--- ./linux/glimp_linux.h.orig	Tue May 23 20:05:59 2006
+++ ./linux/glimp_linux.h	Tue May 23 20:06:00 2006
@@ -21,9 +21,9 @@
 // glimp_linux.h
 //
 
-#ifndef __linux__
+#ifndef __unix__
 #  error You should not be including this file on this platform
-#endif // __linux__
+#endif // __unix__
 
 #ifndef __GLIMP_LINUX_H__
 #define __GLIMP_LINUX_H__
