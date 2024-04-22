--- src/libslic3r/Format/STEP.cpp.orig	2024-04-05 18:42:53 UTC
+++ src/libslic3r/Format/STEP.cpp
@@ -39,7 +39,7 @@ LoadStepFn get_load_step_fn()
 #endif
 
     if (!load_step_fn) {
-        auto libpath = boost::dll::program_location().parent_path();
+        auto libpath = boost::dll::program_location().parent_path().parent_path();
 #ifdef _WIN32
         libpath /= "OCCTWrapper.dll";
         HMODULE module = LoadLibraryW(libpath.wstring().c_str());
@@ -61,6 +61,7 @@ LoadStepFn get_load_step_fn()
 #elif __APPLE__
         load_step_fn = &load_step_internal;
 #else
+        libpath /= "lib";
         libpath /= "OCCTWrapper.so";
         void *plugin_ptr = dlopen(libpath.c_str(), RTLD_NOW | RTLD_GLOBAL);
 
