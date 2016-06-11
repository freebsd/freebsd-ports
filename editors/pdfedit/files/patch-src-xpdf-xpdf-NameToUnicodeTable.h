--- src/xpdf/xpdf/NameToUnicodeTable.h.orig	2016-06-12 03:03:36.755295000 +0900
+++ src/xpdf/xpdf/NameToUnicodeTable.h	2016-06-12 03:03:51.495599000 +0900
@@ -8,7 +8,7 @@
 
 static struct {
   Unicode u;
-  char *name;
+  const char *name;
 } nameToUnicodeTab[] = {
   {0x0021, "!"},
   {0x0023, "#"},
