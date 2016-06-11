--- src/xpdf/xpdf/BuiltinFont.cc.orig	2008-09-09 14:21:13 UTC
+++ src/xpdf/xpdf/BuiltinFont.cc
@@ -39,7 +39,7 @@ BuiltinFontWidths::~BuiltinFontWidths() 
   gfree(tab);
 }
 
-GBool BuiltinFontWidths::getWidth(char *name, Gushort *width) {
+GBool BuiltinFontWidths::getWidth(const char *name, Gushort *width) {
   int h;
   BuiltinFontWidth *p;
 
@@ -53,8 +53,8 @@ GBool BuiltinFontWidths::getWidth(char *
   return gFalse;
 }
 
-int BuiltinFontWidths::hash(char *name) {
-  char *p;
+int BuiltinFontWidths::hash(const char *name) {
+  const char *p;
   unsigned int h;
 
   h = 0;
