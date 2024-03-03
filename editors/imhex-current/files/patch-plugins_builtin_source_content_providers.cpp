--- plugins/builtin/source/content/providers.cpp.orig	2024-02-23 13:52:28 UTC
+++ plugins/builtin/source/content/providers.cpp
@@ -37,7 +37,7 @@ namespace hex::plugin::builtin {
         ContentRegistry::Provider::add<MemoryFileProvider>(false);
         ContentRegistry::Provider::add<ViewProvider>(false);
 
-        #if defined(OS_WINDOWS) ||defined (OS_LINUX)
+        #if defined(OS_WINDOWS)
             ContentRegistry::Provider::add<ProcessMemoryProvider>();
         #endif
 
