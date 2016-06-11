--- src/xpdf/fofi/FoFiEncodings.cc.orig	2016-06-11 10:34:02.955763000 +0900
+++ src/xpdf/fofi/FoFiEncodings.cc	2016-06-11 10:34:35.315168000 +0900
@@ -19,7 +19,7 @@
 // Type 1 and 1C font data
 //------------------------------------------------------------------------
 
-char *fofiType1StandardEncoding[256] = {
+const char *fofiType1StandardEncoding[256] = {
   NULL,
   NULL,
   NULL,
@@ -278,7 +278,7 @@
   NULL
 };
 
-char *fofiType1ExpertEncoding[256] = {
+const char *fofiType1ExpertEncoding[256] = {
   NULL,
   NULL,
   NULL,
@@ -541,7 +541,7 @@
 // Type 1C font data
 //------------------------------------------------------------------------
 
-char *fofiType1CStdStrings[391] = {
+const char *fofiType1CStdStrings[391] = {
   ".notdef",
   "space",
   "exclam",
