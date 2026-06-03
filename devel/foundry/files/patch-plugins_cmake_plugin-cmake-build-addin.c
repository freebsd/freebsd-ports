--- plugins/cmake/plugin-cmake-build-addin.c.orig	2025-10-28 23:23:12 UTC
+++ plugins/cmake/plugin-cmake-build-addin.c
@@ -103,7 +103,7 @@ plugin_cmake_build_addin_load (FoundryBuildAddin *buil
 
   /* DESTDIR= will get set anyway so use something typical */
   if (prefix == NULL)
-    prefix = g_strdup ("/usr");
+    prefix = g_strdup ("%%LOCALBASE%%");
 
   /* TODO: Determine CMakeLists.txt location instead of expecting it
    * at the root of the project. We might defer this to FoundryConfig
