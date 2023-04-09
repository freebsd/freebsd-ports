--- lib/libimhex/include/hex/data_processor/node.hpp.orig	2023-04-04 10:04:22 UTC
+++ lib/libimhex/include/hex/data_processor/node.hpp
@@ -50,6 +50,7 @@ namespace hex::dp {
         struct NodeError {
             Node *node;
             std::string message;
+            NodeError(Node *n, std::string m) : node(n), message(m) {};
         };
 
         void resetOutputData() {
