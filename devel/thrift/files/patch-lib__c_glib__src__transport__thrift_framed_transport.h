--- ./lib/c_glib/src/transport/thrift_framed_transport.h.orig	2011-11-26 23:00:36.000000000 +0400
+++ ./lib/c_glib/src/transport/thrift_framed_transport.h	2011-12-25 15:09:17.000000000 +0400
@@ -22,6 +22,7 @@
 
 #include <glib.h>
 #include <glib-object.h>
+#include <netinet/in.h>
 
 #include "transport/thrift_transport.h"
 
