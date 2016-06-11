--- src/xpdf/fofi/FoFiEncodings.h.orig	2016-06-11 10:35:39.548372000 +0900
+++ src/xpdf/fofi/FoFiEncodings.h	2016-06-11 10:36:01.939673000 +0900
@@ -21,14 +21,14 @@
 // Type 1 and 1C font data
 //------------------------------------------------------------------------
 
-extern char *fofiType1StandardEncoding[256];
-extern char *fofiType1ExpertEncoding[256];
+extern const char *fofiType1StandardEncoding[256];
+extern const char *fofiType1ExpertEncoding[256];
 
 //------------------------------------------------------------------------
 // Type 1C font data
 //------------------------------------------------------------------------
 
-extern char *fofiType1CStdStrings[391];
+extern const char *fofiType1CStdStrings[391];
 extern Gushort fofiType1CISOAdobeCharset[229];
 extern Gushort fofiType1CExpertCharset[166];
 extern Gushort fofiType1CExpertSubsetCharset[87];
