--- src/rpa.c.orig	Tue Feb  1 12:57:33 2005
+++ src/rpa.c	Mon May 23 18:35:47 2005
@@ -27,7 +27,7 @@
 #endif
 
 #include <sys/uio.h>
-#include <stropts.h>
+#include <sys/un.h>
 
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
@@ -196,7 +196,7 @@
 	goto Fail;
     }
     
-    memset(&usb, 0, sizeof(sun));
+    memset(&usb, 0, sizeof(usb));
     usb.sun_family = AF_UNIX;
     strcpy(usb.sun_path, path);
     
@@ -210,7 +210,7 @@
     
     s_snprintf(path, sizeof(path), "%s/%s/unix", PATH_RPAD_DIR, rp->service);
 
-    memset(&usb, 0, sizeof(sun));
+    memset(&usb, 0, sizeof(usb));
     usb.sun_family = AF_UNIX;
     strcpy(usb.sun_path, path);
     
@@ -399,8 +399,6 @@
     msg.msg_iov = iov;
     msg.msg_iovlen = 1;
     msg.msg_name = NULL;
-    msg.msg_accrights = (void *) &rfd;
-    msg.msg_accrightslen = sizeof(rfd);
 
     rfd = -1;
     rcode = -1;
