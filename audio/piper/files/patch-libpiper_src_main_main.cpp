--- libpiper/src/main/main.cpp.orig	2026-09-04 16:40:50 UTC
+++ libpiper/src/main/main.cpp	2026-09-04 16:40:50 UTC
@@ -44,6 +44,7 @@
 
     // Get the path to the piper executable so we can locate espeak-ng-data,
     // etc. next to it.
+#ifndef PIPER_ESPEAK_DATA_DIR
 #ifdef _MSC_VER
     auto exePath = []() -> filesystem::path {
       wchar_t moduleFileName[MAX_PATH] = {0};
@@ -63,16 +64,22 @@
     auto exePath = filesystem::canonical("/proc/self/exe");
 #endif
 #endif
+#endif
 
     if (runConfig.eSpeakDataPath) {
       // User provided path
       // No change needed, it's already a path
     } else {
+#ifdef PIPER_ESPEAK_DATA_DIR
+      // Use the espeak-ng data directory installed by the system package
+      runConfig.eSpeakDataPath = PIPER_ESPEAK_DATA_DIR;
+#else
       // Assume next to piper executable
       runConfig.eSpeakDataPath =
           std::filesystem::absolute(
               exePath.parent_path().append("espeak-ng-data"))
               .string();
+#endif
     }
     if (!runConfig.eSpeakDataPath.has_value()) {
       throw std::runtime_error("eSpeak data path not set");
