--- src/code.l.orig	2015-05-31 19:01:12 UTC
+++ src/code.l
@@ -3695,7 +3695,7 @@ void codeFreeScanner()
 extern "C" { // some bogus code to keep the compiler happy
   void codeYYdummy() { yy_flex_realloc(0,0); } 
 }
-#elif YY_FLEX_SUBMINOR_VERSION<33
+#elif YY_FLEX_MINOR_VERSION==5 && YY_FLEX_SUBMINOR_VERSION<33
 #error "You seem to be using a version of flex newer than 2.5.4 but older than 2.5.33. These versions do NOT work with doxygen! Please use version <=2.5.4 or >=2.5.33 or expect things to be parsed wrongly!"
 #endif
 
