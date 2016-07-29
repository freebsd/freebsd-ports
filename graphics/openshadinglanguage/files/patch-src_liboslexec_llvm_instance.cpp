--- src/liboslexec/llvm_instance.cpp.orig      2016-04-11 19:42:33 UTC
+++ src/liboslexec/llvm_instance.cpp
@@ -1037,7 +103,7 @@ BackendLLVM::run ()
     // Generate the LLVM IR for each layer.  Skip unused layers.
     m_llvm_local_mem = 0;
     llvm::Function* init_func = build_llvm_init ();
-    std::vector<llvm::Function*> funcs (nlayers, NULL);
+    std::vector<llvm::Function*> funcs (nlayers, (llvm::Function*)NULL);
     for (int layer = 0; layer < nlayers; ++layer) {
         set_inst (layer);
