--- src/enet/unix.c.orig	2011-10-21 07:16:43.000000000 +0700
+++ src/enet/unix.c	2011-11-13 16:44:47.000000000 +0700
@@ -30,11 +30,11 @@
 #include <sys/poll.h>
 #endif
 
-#ifndef _SOCKLEN_T
-#ifndef __socklen_t_defined
-typedef int socklen_t;
-#endif
-#endif
+//#ifndef _SOCKLEN_T
+//#ifndef __socklen_t_defined
+//typedef int socklen_t;
+//#endif
+//#endif
 
 #ifndef MSG_NOSIGNAL
 #define MSG_NOSIGNAL 0
