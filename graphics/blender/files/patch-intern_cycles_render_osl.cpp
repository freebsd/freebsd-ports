--- intern/cycles/render/osl.cpp.orig	2013-02-02 23:31:36.000000000 +0100
+++ intern/cycles/render/osl.cpp	2013-02-02 23:31:56.000000000 +0100
@@ -277,7 +277,7 @@
 
 const char *OSLShaderManager::shader_load_bytecode(const string& hash, const string& bytecode)
 {
-	ss->LoadMemoryShader(hash.c_str(), bytecode.c_str());
+	ss->LoadMemoryCompiledShader(hash.c_str(), bytecode.c_str());
 
 	/* this is a bit weak, but works */
 	OSLShaderInfo info;
