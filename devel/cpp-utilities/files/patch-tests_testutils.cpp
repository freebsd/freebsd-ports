--- tests/testutils.cpp.orig	2023-07-05 03:40:48 UTC
+++ tests/testutils.cpp
@@ -621,7 +621,7 @@ std::vector<std::string> TestApplication::readTestfile
     auto binaryPath = std::string();
 #if defined(CPP_UTILITIES_USE_STANDARD_FILESYSTEM) && defined(PLATFORM_UNIX)
     try {
-        binaryPath = std::filesystem::read_symlink("/proc/self/exe").parent_path();
+        binaryPath = std::filesystem::read_symlink("/proc/curproc/file").parent_path();
         binaryPath += '/';
     } catch (const std::filesystem::filesystem_error &e) {
         cerr << Phrases::Warning << "Unable to detect binary path for finding \"srcdirref\": " << e.what() << Phrases::EndFlush;
