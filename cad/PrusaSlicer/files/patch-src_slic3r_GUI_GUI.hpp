--- src/slic3r/GUI/GUI.hpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/GUI.hpp
@@ -74,7 +74,7 @@ void desktop_open_folder(const boost::filesystem::path
 // Ask the destop to open the directory specified by path using the default file explorer.
 void desktop_open_folder(const boost::filesystem::path& path);
 
-#ifdef __linux__
+#if defined(__linux__) || defined (__FreeBSD__)
 // Calling wxExecute on Linux with proper handling of AppImage's env vars.
 // argv example: { "xdg-open", path.c_str(), nullptr }
 void desktop_execute(const char* argv[]);
