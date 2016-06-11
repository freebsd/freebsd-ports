--- src/xpdf/fofi/FoFiTrueType.cc.orig	2016-06-11 10:37:17.000155000 +0900
+++ src/xpdf/fofi/FoFiTrueType.cc	2016-06-11 10:40:14.853257000 +0900
@@ -143,7 +143,7 @@
 //------------------------------------------------------------------------
 
 struct T42Table {
-  char *tag;			// 4-byte tag
+  const char *tag;			// 4-byte tag
   GBool required;		// required by the TrueType spec?
 };
 
@@ -173,7 +173,7 @@
 
 // Glyph names in some arbitrary standard order that Apple uses for
 // their TrueType fonts.
-static char *macGlyphNames[258] = {
+static const char *macGlyphNames[258] = {
   ".notdef",        "null",           "CR",             "space",
   "exclam",         "quotedbl",       "numbersign",     "dollar",
   "percent",        "ampersand",      "quotesingle",    "parenleft",
@@ -2011,7 +2011,7 @@
   }
 }
 
-int FoFiTrueType::seekTable(char *tag) {
+int FoFiTrueType::seekTable(const char *tag) {
   Guint tagI;
   int i;
 
