--- ./lib/c_glib/src/transport/thrift_framed_transport.h.orig	2011-08-11 17:18:58.000000000 +0400
+++ ./lib/c_glib/src/transport/thrift_framed_transport.h	2011-08-26 12:00:03.000000000 +0400
@@ -22,6 +22,7 @@
 
 #include <glib.h>
 #include <glib-object.h>
+#include <netinet/in.h>
 
 #include "transport/thrift_transport.h"
 
