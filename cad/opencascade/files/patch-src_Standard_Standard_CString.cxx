--- src/Standard/Standard_CString.cxx.orig	2014-11-07 16:16:43.000000000 +0100
+++ src/Standard/Standard_CString.cxx	2014-11-16 14:57:27.000000000 +0100
@@ -81,7 +81,7 @@
     // strtod, strtol, strtoll functions. For other system with locale-depended
     // implementations problems may appear if "C" locale is not set explicitly.
     #ifndef __ANDROID__
-      #error System does not support xlocale. Import/export could be broken if C locale did not specified by application.
+      #warning System does not support xlocale. Import/export could be broken if C locale did not specified by application.
     #endif
     #define strtod_l(thePtr, theNextPtr, theLocale)              strtod(thePtr, theNextPtr)
   #endif
