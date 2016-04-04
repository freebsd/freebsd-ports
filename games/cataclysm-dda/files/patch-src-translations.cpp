--- src/translations.cpp.orig	2015-03-09 05:25:34 UTC
+++ src/translations.cpp
@@ -72,7 +72,7 @@ void set_language(bool reload_options)
 
     // Step 2. Bind to gettext domain.
     const char *locale_dir;
-#ifdef __linux__
+#if (defined __linux__ || defined __FreeBSD__)
     if (!FILENAMES["base_path"].empty()) {
         locale_dir = std::string(FILENAMES["base_path"] + "share/locale").c_str();
     } else {
