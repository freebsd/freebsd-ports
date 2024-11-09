--- src/slic3r/GUI/ConfigWizard.hpp.orig	2024-09-18 13:39:04 UTC
+++ src/slic3r/GUI/ConfigWizard.hpp
@@ -54,7 +54,7 @@ namespace DownloaderUtils {
         bool on_finish();
         static bool perform_download_register(const std::string& path);
         static bool perform_url_register();
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         static bool perform_registration_linux;
 #endif // __linux__
     };
