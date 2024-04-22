--- src/slic3r/GUI/ConfigWizard.hpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/ConfigWizard.hpp
@@ -31,7 +31,7 @@ namespace DownloaderUtils {
         wxWindow*   m_parent{ nullptr };
         wxTextCtrl* m_input_path{ nullptr };
         bool        downloader_checked{ false };
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         bool        perform_registration_linux{ false };
 #endif // __linux__
 
@@ -50,7 +50,7 @@ namespace DownloaderUtils {
 
         bool on_finish();
         bool perform_register(const std::string& path_override = {});
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         bool get_perform_registration_linux() { return perform_registration_linux; }
 #endif // __linux__
     };
