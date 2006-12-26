--- ./include/net.h.orig	Mon Dec 25 17:07:02 2006
+++ ./include/net.h	Mon Dec 25 17:07:02 2006
@@ -24,7 +24,7 @@
 #include <windows.h>
 #endif
 #include <winsock2.h>
-#elif defined( __linux__ )
+#elif defined( __unix__ )
 #include <unistd.h>
 #include <sys/socket.h>
 #include <sys/time.h>
