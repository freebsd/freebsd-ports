--- src/xpdf/xpdf/BuiltinFont.h.orig	2008-09-09 14:21:13 UTC
+++ src/xpdf/xpdf/BuiltinFont.h
@@ -23,7 +23,7 @@ class BuiltinFontWidths;
 //------------------------------------------------------------------------
 
 struct BuiltinFont {
-  char *name;
+  const char *name;
   char **defaultBaseEnc;
   short ascent;
   short descent;
@@ -34,7 +34,7 @@ struct BuiltinFont {
 //------------------------------------------------------------------------
 
 struct BuiltinFontWidth {
-  char *name;
+  const char *name;
   Gushort width;
   BuiltinFontWidth *next;
 };
@@ -44,11 +44,11 @@ public:
 
   BuiltinFontWidths(BuiltinFontWidth *widths, int sizeA);
   ~BuiltinFontWidths();
-  GBool getWidth(char *name, Gushort *width);
+  GBool getWidth(const char *name, Gushort *width);
 
 private:
 
-  int hash(char *name);
+  int hash(const char *name);
 
   BuiltinFontWidth **tab;
   int size;
