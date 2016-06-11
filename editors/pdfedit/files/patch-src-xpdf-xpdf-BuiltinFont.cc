--- src/xpdf/xpdf/BuiltinFont.cc.orig	2016-06-12 03:09:00.143158000 +0900
+++ src/xpdf/xpdf/BuiltinFont.cc	2016-06-12 03:09:30.242137000 +0900
@@ -39,7 +39,7 @@
   gfree(tab);
 }
 
-GBool BuiltinFontWidths::getWidth(char *name, Gushort *width) {
+GBool BuiltinFontWidths::getWidth(const char *name, Gushort *width) {
   int h;
   BuiltinFontWidth *p;
 
@@ -53,8 +53,8 @@
   return gFalse;
 }
 
-int BuiltinFontWidths::hash(char *name) {
-  char *p;
+int BuiltinFontWidths::hash(const char *name) {
+  const char *p;
   unsigned int h;
 
   h = 0;
