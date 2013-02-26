--- ./lib/c_glib/src/thrift/transport/thrift_framed_transport.h.orig	2012-10-12 04:58:04.000000000 +0400
+++ ./lib/c_glib/src/thrift/transport/thrift_framed_transport.h	2012-10-16 16:40:46.811818260 +0400
@@ -22,6 +22,7 @@
 
 #include <glib.h>
 #include <glib-object.h>
+#include <netinet/in.h>
 
 #include <thrift/transport/thrift_transport.h>
 
