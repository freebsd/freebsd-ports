--- src/xpdf/fofi/FoFiEncodings.h.orig	2008-09-09 14:21:11 UTC
+++ src/xpdf/fofi/FoFiEncodings.h
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
