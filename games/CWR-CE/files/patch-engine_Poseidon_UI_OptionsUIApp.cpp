--- engine/Poseidon/UI/OptionsUIApp.cpp.orig	2026-08-06 09:21:54 UTC
+++ engine/Poseidon/UI/OptionsUIApp.cpp
@@ -119,8 +119,18 @@ RString GetAppVersion()
 {
 #if defined(_M_X64) || defined(__x86_64__)
     const char* platform = "x64";
-#else
+#elif defined(__aarch64__)
+    const char* platform = "aarch64";
+#elif defined(__arm__)
+    const char* platform = "arm";
+#elif defined(__powerpc64__)
+    const char* platform = "powerpc64";
+#elif defined(__powerpc__)
+    const char* platform = "powerpc";
+#elif defined(__i386__)
     const char* platform = "x86";
+#else
+    const char* platform = "unknown";
 #endif
 
     RString renderer = GEngine ? GEngine->GetRendererName() : "No renderer";
