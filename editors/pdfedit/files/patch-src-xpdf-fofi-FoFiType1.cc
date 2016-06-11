--- src/xpdf/fofi/FoFiType1.cc.orig	2008-09-09 14:21:12 UTC
+++ src/xpdf/fofi/FoFiType1.cc
@@ -194,7 +194,7 @@ void FoFiType1::parse() {
     // get encoding
     } else if (!encoding &&
 	       !strncmp(line, "/Encoding StandardEncoding def", 30)) {
-      encoding = fofiType1StandardEncoding;
+      encoding = (char **)fofiType1StandardEncoding;
     } else if (!encoding &&
 	       !strncmp(line, "/Encoding 256 array", 19)) {
       encoding = (char **)gmallocn(256, sizeof(char *));
