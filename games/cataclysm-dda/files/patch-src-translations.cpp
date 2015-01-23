--- src/translations.cpp.orig	2014-11-17 06:09:38.000000000 +0300
+++ src/translations.cpp	2014-11-30 13:22:06.603147068 +0300
@@ -1,5 +1,6 @@
 #include "translations.h"
 
+#include <sys/param.h>
 #include <string>
 #ifdef LOCALIZE
 #undef __STRICT_ANSI__ // _putenv in minGW need that
@@ -72,7 +73,7 @@ void set_language(bool reload_options)
 
     // Step 2. Bind to gettext domain.
     const char *locale_dir;
-#ifdef __linux__
+#if (defined __linux__ || defined __FreeBSD__)
     if (!FILENAMES["base_path"].empty()) {
         locale_dir = std::string(FILENAMES["base_path"] + "share/locale").c_str();
     } else {
