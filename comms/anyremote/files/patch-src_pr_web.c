--- src/pr_web.c	2013-07-10 11:07:03.922188287 +0200
+++ src/pr_web.c	2013-07-10 11:27:16.319193955 +0200
@@ -33,7 +33,11 @@
 #include <netinet/in.h>
 #include <netdb.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/uio.h>
+#else
 #include <sys/sendfile.h>
+#endif
 
 #define SERVER     "webserver/1.1"
 #define PROTOCOL   "HTTP/1.1"
@@ -272,7 +276,7 @@
 static void sendFile(_WebClientConnection* cc, char *path, struct stat *statbuf)
 {
     int fd = cc->connDescriptor;
-    int bytes_sent;
+    ssize_t bytes_sent;
 
     INFO2("[WS]: sendFile %s",path);
 
@@ -293,8 +297,12 @@
         int length = S_ISREG(statbuf->st_mode) ? statbuf->st_size : -1;
         sendHeaders(cc, 200, "OK", NULL, get_mime_type(path), length, statbuf->st_mtime);
 
+#ifdef __FreeBSD__
+        int err = sendfile(fdout, fd, 0, length, NULL, &bytes_sent, 0);
+#else
         bytes_sent = sendfile(fd,fdout,NULL,length);
-    
+        int err = 0;
+#endif
         /*while ((n = fread(data, 1, sizeof(data), file)) > 0) {
             //INFO2("read %d bytes from file",n);
 
@@ -305,7 +313,7 @@
             }
         }*/
     
-        if (length != bytes_sent) {
+        if (err || length != bytes_sent) {
             ERROR2("[WS]: Error on send file %s", path);
         }
 
