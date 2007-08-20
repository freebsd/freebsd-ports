--- src/ports/linux/qal_linux.h	Mon Apr  2 10:10:24 2007
+++ src/ports/linux/qal_linux.h	Mon Apr  2 10:17:39 2007
@@ -28,7 +28,9 @@
 
 
 #ifndef __linux__
+#	ifndef __FreeBSD__
 #error "You should not be including this file on this platform"
+#	endif
 #endif
 
 
