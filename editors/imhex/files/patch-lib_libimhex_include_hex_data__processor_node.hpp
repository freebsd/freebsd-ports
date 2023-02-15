--- lib/libimhex/include/hex/data_processor/node.hpp.orig	2023-02-12 18:24:04 UTC
+++ lib/libimhex/include/hex/data_processor/node.hpp
@@ -49,6 +49,7 @@ namespace hex::dp {
         struct NodeError {
             Node *node;
             std::string message;
+            NodeError(Node *n, std::string m) : node(n), message(m) {};
         };
 
         void resetOutputData() {
