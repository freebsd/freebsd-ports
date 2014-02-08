--- ./include/vki/vki-freebsd.h.orig	2014-02-08 15:00:31.591069799 -0600
+++ ./include/vki/vki-freebsd.h	2014-02-08 15:00:39.993068845 -0600
@@ -681,6 +681,7 @@
 
 #define VKI_SOCK_STREAM	1
 
+#include <sys/types.h>
 #include <netinet/tcp.h>
 
 #define VKI_TCP_NODELAY  TCP_NODELAY
