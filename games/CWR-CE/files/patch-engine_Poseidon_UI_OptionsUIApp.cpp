--- engine/Poseidon/UI/OptionsUIApp.cpp.orig
+++ engine/Poseidon/UI/OptionsUIApp.cpp
@@ -120,6 +120,8 @@
 {
 #if defined(_M_X64) || defined(__x86_64__)
     const char* platform = "x64";
+#elif defined(__aarch64__)
+    const char* platform = "aarch64";
 #else
     const char* platform = "x86";
 #endif
