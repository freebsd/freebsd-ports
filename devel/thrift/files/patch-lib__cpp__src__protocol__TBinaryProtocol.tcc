--- ./lib/cpp/src/protocol/TBinaryProtocol.tcc.orig       2011-11-26 23:00:40.000000000 +0400
+++ ./lib/cpp/src/protocol/TBinaryProtocol.tcc     2011-12-08 23:53:23.000000000 +0400
@@ -23,7 +23,7 @@
 #include "TBinaryProtocol.h"
 
 #include <limits>
-
+#include <netinet/in.h>
 
 namespace apache { namespace thrift { namespace protocol {
 
