--- core/roscpp/src/libros/network.cpp.orig	2010-07-21 01:48:07.000000000 +0200
+++ core/roscpp/src/libros/network.cpp	2010-12-03 20:18:21.000000000 +0100
@@ -34,6 +34,9 @@
 #include <ros/assert.h>
 
 #include <netinet/in.h>
+#ifdef HAVE_IFADDRS_H
+  #include <sys/types.h>
+#endif
 #include <sys/socket.h>
 #include <netdb.h>
 
