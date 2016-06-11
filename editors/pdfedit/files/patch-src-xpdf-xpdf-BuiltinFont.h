--- src/xpdf/xpdf/BuiltinFont.h.orig	2016-06-12 03:07:21.081040000 +0900
+++ src/xpdf/xpdf/BuiltinFont.h	2016-06-12 03:08:04.015283000 +0900
@@ -23,7 +23,7 @@
 //------------------------------------------------------------------------
 
 struct BuiltinFont {
-  char *name;
+  const char *name;
   char **defaultBaseEnc;
   short ascent;
   short descent;
@@ -34,7 +34,7 @@
 //------------------------------------------------------------------------
 
 struct BuiltinFontWidth {
-  char *name;
+  const char *name;
   Gushort width;
   BuiltinFontWidth *next;
 };
@@ -44,11 +44,11 @@
 
   BuiltinFontWidths(BuiltinFontWidth *widths, int sizeA);
   ~BuiltinFontWidths();
-  GBool getWidth(char *name, Gushort *width);
+  GBool getWidth(const char *name, Gushort *width);
 
 private:
 
-  int hash(char *name);
+  int hash(const char *name);
 
   BuiltinFontWidth **tab;
   int size;
