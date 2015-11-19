--- src/vhdlcode.l.orig	2015-11-19 06:41:43 UTC
+++ src/vhdlcode.l
@@ -1613,7 +1613,7 @@ void codeFreeVhdlScanner()
 extern "C" { // some bogus code to keep the compiler happy
   void vhdlcodeYYdummy() { yy_flex_realloc(0,0); } 
 }
-#elif YY_FLEX_SUBMINOR_VERSION<33
+#elif YY_FLEX_MINOR_VERSION==5 && YY_FLEX_SUBMINOR_VERSION<33
 #error "You seem to be using a version of flex newer than 2.5.4 but older than 2.5.33. These versions do NOT work with doxygen! Please use version <=2.5.4 or >=2.5.33 or expect things to be parsed wrongly!"
 #endif
 
