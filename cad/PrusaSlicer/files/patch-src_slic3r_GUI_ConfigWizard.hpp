--- src/slic3r/GUI/ConfigWizard.hpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/ConfigWizard.hpp
@@ -53,7 +53,7 @@ namespace DownloaderUtils {
 
         bool on_finish();
         static bool perform_register(const std::string& path);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         static bool perform_registration_linux;
 #endif // __linux__
     };
