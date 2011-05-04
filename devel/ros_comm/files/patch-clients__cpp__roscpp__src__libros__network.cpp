--- ./clients/cpp/roscpp/src/libros/network.cpp.orig	2011-03-02 01:15:17.000000000 +0100
+++ ./clients/cpp/roscpp/src/libros/network.cpp	2011-03-20 15:22:54.000000000 +0100
@@ -34,6 +34,9 @@
 #include <ros/assert.h>
 
 #include <netinet/in.h>
+#ifdef HAVE_IFADDRS_H
+  #include <sys/types.h>
+#endif
 #include <sys/socket.h>
 #include <netdb.h>
 
