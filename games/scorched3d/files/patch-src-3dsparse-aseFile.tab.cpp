--- src/3dsparse/aseFile.tab.cpp.orig	Mon Nov  3 20:54:39 2003
+++ src/3dsparse/aseFile.tab.cpp	Mon Nov  3 20:55:14 2003
@@ -5,7 +5,7 @@
 
 #define YYBISON 1  /* Identify Bison output.  */
 
-#define alloca
+/* #define alloca */
 
 #define yyparse aseparse
 #define yylex aselex
