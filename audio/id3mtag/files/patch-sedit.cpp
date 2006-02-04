--- sedit.cpp.orig	Wed Feb  1 03:27:18 2006
+++ sedit.cpp	Sat Feb  4 15:57:59 2006
@@ -17,7 +17,7 @@
 using namespace std;
 using namespace charset;
 
-#if defined(__DJGPP__) || defined(__BORLANDC__)  // crappy wide char support
+#if (__FreeBSD_version_ < 500000)
 #    define towupper toupper
 #    define towlower tolower
 #    define iswalnum isalnum
