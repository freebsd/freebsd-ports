--- src/Osenc.cpp.orig	2020-01-13 17:37:57 UTC
+++ src/Osenc.cpp
@@ -99,7 +99,7 @@ void OpenCPN_OGR_OSENC_ErrorHandler( CPLErr eErrClass,
 
 #ifndef __WXMSW__    
     if( eErrClass == CE_Fatal ) {
-        longjmp( env_osenc_ogrf, 1 );                  // jump back to the setjmp() point
+        siglongjmp( env_osenc_ogrf, 1 );                  // jump back to the setjmp() point
     }
 #endif
     
