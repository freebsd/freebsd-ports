--- libpit/source/libpit.h.orig	2017-05-11 18:34:25 UTC
+++ libpit/source/libpit.h
@@ -25,14 +25,6 @@
 #pragma warning(disable : 4996)
 #endif
 
-#if (!(defined _MSC_VER) || (_MSC_VER < 1700))
-
-#ifndef nullptr
-#define nullptr 0
-#endif
-
-#endif
-
 // C/C++ Standard Library
 #include <cstring>
 #include <string>
