
$FreeBSD$

--- src/IIOP/giop-msg-buffer.c.orig	Mon Mar 11 14:40:02 2002
+++ src/IIOP/giop-msg-buffer.c	Tue Mar 12 16:43:03 2002
@@ -34,7 +34,8 @@
 #include "IIOP.h"
 #include "IIOP-private.h"
 
-#define MAX_LIMITED_IOVECS 16
+#define MAX_LIMITED_IOVECS MAXIOV
+#define HAVE_LIMITED_WRITEV
 
 #ifdef        __GNUC__
 #define       PACKED __attribute__((packed))
