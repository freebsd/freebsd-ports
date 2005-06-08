--- src/language.cpp.orig	Tue Jun  7 19:36:19 2005
+++ src/language.cpp	Tue Jun  7 19:36:39 2005
@@ -124,12 +124,12 @@
 static void wesnoth_setlocale(int category, std::string const &slocale)
 {
 	char const *locale = slocale.c_str();
-#ifdef __BEOS__
+
 	if(setenv ("LANG", locale, 1) == -1)
 		std::cerr << "setenv LANG failed: " << strerror(errno);
 	if(setenv ("LC_ALL", locale, 1) == -1)
 		std::cerr << "setenv LC_ALL failed: " << strerror(errno);
-#endif
+
 #ifdef __APPLE__
 	if(setenv ("LANGUAGE", locale, 1) == -1)
 		std::cerr << "setenv LANGUAGE failed: " << strerror(errno);
