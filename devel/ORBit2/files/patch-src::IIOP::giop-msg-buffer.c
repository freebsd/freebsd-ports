
$FreeBSD$

--- src/IIOP/giop-msg-buffer.c.orig	Wed Oct  3 09:51:21 2001
+++ src/IIOP/giop-msg-buffer.c	Sat Oct 27 15:52:11 2001
@@ -34,10 +34,6 @@
 #include "IIOP.h"
 #include "IIOP-private.h"
 
-#ifdef HAVE_LIMITED_WRITEV
-#define writev g_writev
-#endif
-
 /* type defs */
 
 #ifdef        __GNUC__
@@ -197,7 +193,7 @@
 	    sum);
   }
 #endif
-  res = writev(fd, curvec, nvecs);
+  res = g_writev(fd, curvec, nvecs);
 
   sum = (GIOP_MESSAGE_BUFFER(send_buffer)->message_header.message_size + sizeof(GIOPMessageHeader));
   if(res < sum) {
@@ -227,7 +223,7 @@
 
     fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) & ~O_NONBLOCK);
 
-    t = writev(fd, curvec, nvecs);
+    t = g_writev(fd, curvec, nvecs);
 
     fcntl(fd, F_SETFL, fcntl(fd, F_GETFL, 0) | O_NONBLOCK);
 
