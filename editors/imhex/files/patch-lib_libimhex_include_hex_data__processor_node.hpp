--- lib/libimhex/include/hex/data_processor/node.hpp.orig	2022-10-08 08:03:47 UTC
+++ lib/libimhex/include/hex/data_processor/node.hpp
@@ -46,6 +46,7 @@ namespace hex::dp {
         struct NodeError {
             Node *node;
             std::string message;
+            NodeError(Node *n, std::string m) : node(n), message(m) {};
         };
 
         void resetOutputData() {
