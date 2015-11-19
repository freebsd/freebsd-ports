--- src/xmlcode.l.orig	2015-05-31 19:01:12 UTC
+++ src/xmlcode.l
@@ -407,7 +407,7 @@ void resetXmlCodeParserState() 
 extern "C" { // some bogus code to keep the compiler happy
   void xmlcodeYYdummy() { yy_flex_realloc(0,0); } 
 }
-#elif YY_FLEX_SUBMINOR_VERSION<33
+#elif YY_FLEX_MINOR_VERSION==5 && YY_FLEX_SUBMINOR_VERSION<33
 #error "You seem to be using a version of flex newer than 2.5.4. These are currently incompatible with 2.5.4, and do NOT work with doxygen! Please use version 2.5.4 or expect things to be parsed wrongly! A bug report has been submitted (#732132)."
 #endif
 
