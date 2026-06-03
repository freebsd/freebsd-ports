--- main/updater/source/main.cpp.orig	2026-01-25 11:36:14 UTC
+++ main/updater/source/main.cpp
@@ -107,7 +107,7 @@ std::optional<std::fs::path> downloadUpdate(const std:
 #elif defined(__arm64__) || defined(_ARM64_) || defined(__aarch64__) || defined(_M_ARM64)
     #define ARCH_DEPENDENT(x86_64, arm64) arm64
 #else
-    #error "Unsupported architecture for updater"
+    #define ARCH_DEPENDENT(x86_64, arm64) ""
 #endif
 
 std::string_view getUpdateArtifactEnding() {
@@ -333,4 +333,4 @@ int main(int argc, char **argv) {
     } else {
         return EXIT_SUCCESS;
     }
-}
\ No newline at end of file
+}
