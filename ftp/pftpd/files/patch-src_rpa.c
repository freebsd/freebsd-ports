--- src/rpa.c.orig	Tue Feb  1 12:57:33 2005
+++ src/rpa.c	Mon May 23 18:35:47 2005
@@ -27,7 +27,7 @@
 #endif
 
 #include <sys/uio.h>
-#include <stropts.h>
+#include <sys/un.h>
 
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
@@ -198,14 +198,14 @@
     }
     
     strcpy(path, "/var/tmp/rpa.XXXXXX");
-    mktemp(path);
+    mkstemp(path);
     if (!path[0])
     {
 	syslog(LOG_ERR, "rpa_unix_open: unable to create local socket name");
 	goto Fail;
     }
     
-    memset(&usb, 0, sizeof(sun));
+    memset(&usb, 0, sizeof(usb));
     usb.sun_family = AF_UNIX;
     strcpy(usb.sun_path, path);
     
@@ -219,7 +219,7 @@
     
     s_snprintf(path, sizeof(path), "%s/%s/unix", PATH_RPAD_DIR, rp->service);
 
-    memset(&usb, 0, sizeof(sun));
+    memset(&usb, 0, sizeof(usb));
     usb.sun_family = AF_UNIX;
     strcpy(usb.sun_path, path);
     
@@ -408,8 +408,6 @@
     msg.msg_iov = iov;
     msg.msg_iovlen = 1;
     msg.msg_name = NULL;
-    msg.msg_accrights = (void *) &rfd;
-    msg.msg_accrightslen = sizeof(rfd);
 
     rfd = -1;
     rcode = -1;
