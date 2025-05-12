--- src/libslic3r/Format/STEP.cpp.orig	2025-04-10 11:26:51 UTC
+++ src/libslic3r/Format/STEP.cpp
@@ -42,7 +42,7 @@ LoadStepFn get_load_step_fn()
 #endif
 
     if (!load_step_fn) {
-        auto libpath = boost::dll::program_location().parent_path();
+        auto libpath = boost::dll::program_location().parent_path().parent_path();
 #ifdef _WIN32
         libpath /= "OCCTWrapper.dll";
         HMODULE module = LoadLibraryW(libpath.wstring().c_str());
@@ -64,6 +64,7 @@ LoadStepFn get_load_step_fn()
 #elif __APPLE__
         load_step_fn = &load_step_internal;
 #else
+        libpath /= "lib";
         libpath /= "OCCTWrapper.so";
         void *plugin_ptr = dlopen(libpath.c_str(), RTLD_NOW | RTLD_GLOBAL);
 
