--- user.cc.orig	Thu Nov 28 14:12:38 2002
+++ user.cc	Thu Nov 28 14:12:54 2002
@@ -67,7 +67,7 @@
 int User::init()
 {
     struct sockaddr_in  addr;
-    size_t              size;
+    socklen_t           size;
     struct hostent     *host;
     int                 sockn;
 
