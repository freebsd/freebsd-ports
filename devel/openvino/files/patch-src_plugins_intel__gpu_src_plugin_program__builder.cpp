--- src/plugins/intel_gpu/src/plugin/program_builder.cpp.orig	2026-04-10 09:41:30 UTC
+++ src/plugins/intel_gpu/src/plugin/program_builder.cpp
@@ -23,7 +23,7 @@
 #include "intel_gpu/op/placeholder.hpp"
 #include "openvino/util/pp.hpp"
 
-#ifdef __linux__
+#ifdef __FreeBSD__
 # include <dlfcn.h>
 #endif
 
@@ -85,7 +85,7 @@ ProgramBuilder::ProgramBuilder(std::shared_ptr<ov::Mod
         (LPCSTR)CustomLayer::LoadFromFile,
         &nModule);
     GetModuleFileName(nModule, mpath, sizeof(mpath));
-#elif __linux__
+#elif __FreeBSD__
     Dl_info dl_info;
     dladdr(reinterpret_cast<void *>(CustomLayer::LoadFromFile), &dl_info);
     const char* mpath = dl_info.dli_fname;
