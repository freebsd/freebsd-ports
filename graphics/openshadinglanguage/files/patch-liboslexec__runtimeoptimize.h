--- ./liboslexec/runtimeoptimize.h.orig	2013-07-12 08:31:18.000000000 +0930
+++ ./liboslexec/runtimeoptimize.h	2013-11-03 18:07:25.656119123 +1030
@@ -345,7 +345,8 @@
     /// Helper: return the ptr to the symbol that is the argnum-th
     /// argument to the given op.
     Symbol *opargsym (const Opcode &op, int argnum) {
-        return inst()->argsymbol (op.firstarg()+argnum);
+        return (argnum < op.nargs()) ?
+                    inst()->argsymbol (op.firstarg()+argnum) : NULL;
     }
 
     /// Create an llvm function for the whole shader group, JIT it,
@@ -826,7 +827,7 @@
     ///
     llvm::BasicBlock *llvm_exit_instance_block () {
         if (! m_exit_instance_block) {
-            std::string name = Strutil::format ("%s_%d_exit_", inst()->layername().c_str(), inst()->id());
+            std::string name = Strutil::format ("%s_%d_exit_", inst()->layername(), inst()->id());
             m_exit_instance_block = llvm_new_basic_block (name);
         }
         return m_exit_instance_block;
@@ -887,8 +888,8 @@
     int m_local_unknown_message_sent;   ///< Non-const setmessage in this inst
     std::vector<ustring> m_local_messages_sent; ///< Messages set in this inst
     std::vector<int> m_bblockids;       ///< Basic block IDs for each op
-    std::vector<bool> m_in_conditional; ///< Whether each op is in a cond
-    std::vector<bool> m_in_loop;        ///< Whether each op is in a loop
+    std::vector<char> m_in_conditional; ///< Whether each op is in a cond
+    std::vector<char> m_in_loop;        ///< Whether each op is in a loop
     std::vector<int> m_layer_remap;     ///< Remapping of layer ordering
     std::set<int> m_layers_already_run; ///< List of layers run
     int m_num_used_layers;              ///< Number of layers actually used
