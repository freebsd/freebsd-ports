--- ./lib/cpp/src/thrift/protocol/TBinaryProtocol.tcc.orig	2013-08-15 18:04:29.000000000 +0400
+++ ./lib/cpp/src/thrift/protocol/TBinaryProtocol.tcc	2013-10-16 01:15:53.000000000 +0400
@@ -23,7 +23,7 @@
 #include <thrift/protocol/TBinaryProtocol.h>
 
 #include <limits>
-
+#include <netinet/in.h>
 
 namespace apache { namespace thrift { namespace protocol {
 
