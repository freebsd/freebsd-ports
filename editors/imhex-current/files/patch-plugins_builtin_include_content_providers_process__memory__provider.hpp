--- plugins/builtin/include/content/providers/process_memory_provider.hpp.orig	2024-02-23 13:28:35 UTC
+++ plugins/builtin/include/content/providers/process_memory_provider.hpp
@@ -1,6 +1,6 @@
 #pragma once
 
-#if defined(OS_WINDOWS) || defined (OS_LINUX)
+#if defined(OS_WINDOWS)
 
 #include <hex/providers/provider.hpp>
 #include <hex/api/localization_manager.hpp>
