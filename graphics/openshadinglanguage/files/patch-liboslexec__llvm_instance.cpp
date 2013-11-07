--- ./liboslexec/llvm_instance.cpp.orig	2013-07-12 08:31:18.000000000 +0930
+++ ./liboslexec/llvm_instance.cpp	2013-11-03 18:07:25.654119237 +1030
@@ -809,7 +809,7 @@
 {
     // Make a layer function: void layer_func(ShaderGlobals*, GroupData*)
     // Note that the GroupData* is passed as a void*.
-    std::string unique_layer_name = Strutil::format ("%s_%d", inst()->layername().c_str(), inst()->id());
+    std::string unique_layer_name = Strutil::format ("%s_%d", inst()->layername(), inst()->id());
 
     m_layer_func = llvm::cast<llvm::Function>(m_llvm_module->getOrInsertFunction(unique_layer_name,
                     llvm_type_void(), llvm_type_sg_ptr(),
