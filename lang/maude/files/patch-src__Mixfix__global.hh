--- ./src/Mixfix/global.hh.orig	2006-10-07 01:09:50.000000000 +0200
+++ ./src/Mixfix/global.hh	2011-10-12 14:05:37.000000000 +0200
@@ -36,6 +36,7 @@
 
 #define PRELUDE_NAME	"prelude.maude"
 #define MAUDE_LIB	"MAUDE_LIB"
+#define MAUDE_DATADIR	"%%DATADIR%%"
 
 bool
 findPrelude(string& directory, string& fileName);
