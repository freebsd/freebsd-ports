--- lib/libimhex/include/hex/data_processor/node.hpp.orig	2022-08-14 15:02:06 UTC
+++ lib/libimhex/include/hex/data_processor/node.hpp
@@ -45,6 +45,7 @@ namespace hex::dp {
         struct NodeError {
             Node *node;
             std::string message;
+            NodeError(Node *n, std::string m) : node(n), message(m) {};
         };
 
         void resetOutputData() {
