--- ./lib/cpp/src/thrift/protocol/TBinaryProtocol.tcc.orig	2012-10-12 04:58:06.000000000 +0400
+++ ./lib/cpp/src/thrift/protocol/TBinaryProtocol.tcc	2012-10-16 16:41:57.890819558 +0400
@@ -23,7 +23,7 @@
 #include "TBinaryProtocol.h"
 
 #include <limits>
-
+#include <netinet/in.h>
 
 namespace apache { namespace thrift { namespace protocol {
 
