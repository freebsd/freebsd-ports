--- dispatch/glproc_gl.cpp.orig	2017-10-13 17:18:18 UTC
+++ dispatch/glproc_gl.cpp
@@ -200,7 +200,7 @@ void * _libgl_sym(const char *symbol)
          * exposes symbols to it.
          */
 
-        _libGlHandle = _dlopen(libgl_filename, RTLD_GLOBAL | RTLD_LAZY | RTLD_DEEPBIND);
+        _libGlHandle = _dlopen(libgl_filename, RTLD_GLOBAL | RTLD_LAZY);
         if (!_libGlHandle) {
             os::log("apitrace: error: couldn't find libGL.so\n");
             return NULL;
