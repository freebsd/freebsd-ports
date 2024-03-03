--- plugins/builtin/source/content/providers/process_memory_provider.cpp.orig	2024-02-23 13:35:26 UTC
+++ plugins/builtin/source/content/providers/process_memory_provider.cpp
@@ -1,4 +1,4 @@
-#if defined(OS_WINDOWS) || defined (OS_LINUX)
+#if defined(OS_WINDOWS)
 
 #include <content/providers/process_memory_provider.hpp>
 
