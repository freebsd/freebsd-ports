--- lib/cpp/src/thrift/protocol/TBinaryProtocol.tcc.orig	2021-02-04 23:07:31 UTC
+++ lib/cpp/src/thrift/protocol/TBinaryProtocol.tcc
@@ -25,6 +25,8 @@
 
 #include <limits>
 
+#include <netinet/in.h>
+
 namespace apache {
 namespace thrift {
 namespace protocol {
