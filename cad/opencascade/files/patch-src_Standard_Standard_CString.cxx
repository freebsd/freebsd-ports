--- src/Standard/Standard_CString.cxx.orig	2014-04-29 11:40:41.000000000 +0200
+++ src/Standard/Standard_CString.cxx	2014-10-18 16:05:36.000000000 +0200
@@ -94,7 +94,7 @@
   // So we switch to C locale temporarily
   #define SAVE_TL() Standard_CLocaleSentry aLocaleSentry;
   #ifndef HAVE_XLOCALE_H
-    #error System does not support xlocale. Import/export could be broken if C locale did not specified by application.
+    // #error System does not support xlocale. Import/export could be broken if C locale did not specified by application.
     #define strtod_l(thePtr, theNextPtr, theLocale)              strtod(thePtr, theNextPtr)
   #endif
   #define vprintf_l(theLocale, theFormat, theArgPtr)             vprintf(theFormat, theArgPtr)
