--- src/xpdf/xpdf/NameToUnicodeTable.h.orig	2006-02-04 15:51:34 UTC
+++ src/xpdf/xpdf/NameToUnicodeTable.h
@@ -8,7 +8,7 @@
 
 static struct {
   Unicode u;
-  char *name;
+  const char *name;
 } nameToUnicodeTab[] = {
   {0x0021, "!"},
   {0x0023, "#"},
