--- src/xpdf/fofi/FoFiTrueType.cc.orig	2009-09-11 12:02:56 UTC
+++ src/xpdf/fofi/FoFiTrueType.cc
@@ -143,7 +143,7 @@ static int cmpTrueTypeTableTag(const voi
 //------------------------------------------------------------------------
 
 struct T42Table {
-  char *tag;			// 4-byte tag
+  const char *tag;			// 4-byte tag
   GBool required;		// required by the TrueType spec?
 };
 
@@ -173,7 +173,7 @@ static T42Table t42Tables[nT42Tables] = 
 
 // Glyph names in some arbitrary standard order that Apple uses for
 // their TrueType fonts.
-static char *macGlyphNames[258] = {
+static const char *macGlyphNames[258] = {
   ".notdef",        "null",           "CR",             "space",
   "exclam",         "quotedbl",       "numbersign",     "dollar",
   "percent",        "ampersand",      "quotesingle",    "parenleft",
@@ -2011,7 +2011,7 @@ void FoFiTrueType::readPostTable() {
   }
 }
 
-int FoFiTrueType::seekTable(char *tag) {
+int FoFiTrueType::seekTable(const char *tag) {
   Guint tagI;
   int i;
 
