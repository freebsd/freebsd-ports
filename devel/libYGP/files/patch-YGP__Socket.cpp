--- ./YGP/Socket.cpp.orig	Thu Aug 10 04:08:18 2006
+++ ./YGP/Socket.cpp	Sun Aug 20 14:16:06 2006
@@ -58,7 +58,6 @@
 typedef size_t  ssize_t;
 #endif
 #ifndef HAVE_SOCKLEN_T
-typedef int socklen_t;
 #endif
 
 
