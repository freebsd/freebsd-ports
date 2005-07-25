--- src/language.cpp.orig	Mon Jul 25 13:44:10 2005
+++ src/language.cpp	Mon Jul 25 13:45:47 2005
@@ -133,12 +133,10 @@
 	unsetenv ("LANGUAGE"); // void so no return value to check
 #endif
 
-#ifdef __BEOS__
 	if(setenv ("LANG", locale, 1) == -1)
 		std::cerr << "setenv LANG failed: " << strerror(errno);
 	if(setenv ("LC_ALL", locale, 1) == -1)
 		std::cerr << "setenv LC_ALL failed: " << strerror(errno);
-#endif
 #ifdef __APPLE__
 	if(setenv ("LANGUAGE", locale, 1) == -1)
 		std::cerr << "setenv LANGUAGE failed: " << strerror(errno);
