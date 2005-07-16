--- libgamin/gam_api.c.orig	Sat Jul 16 14:50:35 2005
+++ libgamin/gam_api.c	Sat Jul 16 15:05:33 2005
@@ -14,6 +14,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <sys/uio.h>
+#include <string.h>
 #include "fam.h"
 #include "gam_protocol.h"
 #include "gam_data.h"
@@ -421,7 +422,7 @@ gamin_write_credential_byte(int fd)
 {
     char data[2] = { 0, 0 };
     int written;
-#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
     struct {
 	    struct cmsghdr hdr;
 	    struct cmsgcred cred;
@@ -445,7 +446,7 @@ gamin_write_credential_byte(int fd)
 #endif
 
 retry:
-#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
     written = sendmsg(fd, &msg, 0);
 #else
     written = write(fd, &data[0], 1);
@@ -655,7 +656,7 @@ gamin_check_cred(GAMDataPtr conn, int fd
 
     s_uid = getuid();
 
-#if defined(LOCAL_CREDS) && defined(HAVE_CMSGCRED)
+#if defined(LOCAL_CREDS) && defined(HAVE_CMSGCRED) && !defined(__FreeBSD__)
     /* Set the socket to receive credentials on the next message */
     {
         int on = 1;
