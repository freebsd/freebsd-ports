--- src/slic3r/GUI/ConfigWizard.hpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/ConfigWizard.hpp
@@ -50,7 +50,7 @@ namespace DownloaderUtils {
         bool on_finish();
         static bool perform_download_register(const std::string& path);
         static bool perform_url_register();
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         static bool perform_registration_linux;
 #endif // __linux__
     };
