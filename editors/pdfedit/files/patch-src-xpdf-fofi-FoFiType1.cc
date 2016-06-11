--- src/xpdf/fofi/FoFiType1.cc.orig	2016-06-11 10:43:43.363657000 +0900
+++ src/xpdf/fofi/FoFiType1.cc	2016-06-11 10:44:21.857241000 +0900
@@ -194,7 +194,7 @@
     // get encoding
     } else if (!encoding &&
 	       !strncmp(line, "/Encoding StandardEncoding def", 30)) {
-      encoding = fofiType1StandardEncoding;
+      encoding = (char **)fofiType1StandardEncoding;
     } else if (!encoding &&
 	       !strncmp(line, "/Encoding 256 array", 19)) {
       encoding = (char **)gmallocn(256, sizeof(char *));
