--- src/Standard/Standard_CString.cxx.orig	2013-05-15 15:59:21.000000000 +0700
+++ src/Standard/Standard_CString.cxx	2013-05-15 15:59:52.000000000 +0700
@@ -274,7 +274,7 @@
   // So we switch to C locale temporarily
   #define SAVE_TL() Standard_CLocaleSentry aLocaleSentry;
   #ifndef HAVE_XLOCALE_H
-    #error System does not support xlocale. Import/export could be broken if C locale did not specified by application.
+//    #error System does not support xlocale. Import/export could be broken if C locale did not specified by application.
     #define strtod_l(thePtr, theNextPtr, theLocale)              strtod(thePtr, theNextPtr)
   #endif
   #define vprintf_l(theLocale, theFormat, theArgPtr)             vprintf(theFormat, theArgPtr)
