--- src/xpdf/fofi/FoFiEncodings.cc.orig	2008-09-09 14:21:11 UTC
+++ src/xpdf/fofi/FoFiEncodings.cc
@@ -19,7 +19,7 @@
 // Type 1 and 1C font data
 //------------------------------------------------------------------------
 
-char *fofiType1StandardEncoding[256] = {
+const char *fofiType1StandardEncoding[256] = {
   NULL,
   NULL,
   NULL,
@@ -278,7 +278,7 @@ char *fofiType1StandardEncoding[256] = {
   NULL
 };
 
-char *fofiType1ExpertEncoding[256] = {
+const char *fofiType1ExpertEncoding[256] = {
   NULL,
   NULL,
   NULL,
@@ -541,7 +541,7 @@ char *fofiType1ExpertEncoding[256] = {
 // Type 1C font data
 //------------------------------------------------------------------------
 
-char *fofiType1CStdStrings[391] = {
+const char *fofiType1CStdStrings[391] = {
   ".notdef",
   "space",
   "exclam",
