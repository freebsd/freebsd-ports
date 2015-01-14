--- cmake/Modules/WaffleDefineCompilerFlags.cmake.orig	2014-12-09 22:33:50.000000000 +0100
+++ cmake/Modules/WaffleDefineCompilerFlags.cmake	2015-01-02 15:29:36.754344546 +0100
@@ -50,7 +50,7 @@
     waffle_add_c_flag("-Werror=int-conversion" WERROR_INT_CONVERSION)
     waffle_add_c_flag("-fvisibility=hidden" WITH_VISIBILITY_HIDDEN)
 
-    if(waffle_on_linux)
+    if(waffle_on_linux OR waffle_on_freebsd)
         # On MacOS, the SSE2 headers trigger this error.
         waffle_add_c_flag("-Werror=missing-prototypes" WERROR_MISSING_PROTOTYPES)
     endif()
@@ -97,7 +97,7 @@
     add_definitions(-DWAFFLE_HAS_CGL)
 endif()
 
-if(waffle_on_linux)
+if(waffle_on_linux OR waffle_on_freebsd)
     if(waffle_has_glx)
         add_definitions(-DWAFFLE_HAS_GLX)
     endif()
