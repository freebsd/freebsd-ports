--- lib/cpp/src/thrift/protocol/TBinaryProtocol.tcc.orig	2015-10-13 19:19:23 UTC
+++ lib/cpp/src/thrift/protocol/TBinaryProtocol.tcc
@@ -24,6 +24,8 @@
 
 #include <limits>
 
+#include <netinet/in.h>
+
 namespace apache {
 namespace thrift {
 namespace protocol {
