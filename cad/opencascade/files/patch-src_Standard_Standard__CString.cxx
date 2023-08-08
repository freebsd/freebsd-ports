--- src/Standard/Standard_CString.cxx.orig	2022-09-30 11:54:05 UTC
+++ src/Standard/Standard_CString.cxx
@@ -80,7 +80,7 @@ Standard_Integer HashCodes (const Standard_CString the
     // strtod, strtol, strtoll functions. For other system with locale-depended
     // implementations problems may appear if "C" locale is not set explicitly.
     #if !defined(__ANDROID__) && !defined(__QNX__) && !defined(__MINGW32__)
-      #error System does not support xlocale. Import/export could be broken if C locale did not specified by application.
+      #warning System does not support xlocale. Import/export could be broken if C locale did not specified by application.
     #endif
     #define strtod_l(thePtr, theNextPtr, theLocale)              strtod(thePtr, theNextPtr)
   #endif
