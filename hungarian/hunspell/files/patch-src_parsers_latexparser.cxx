--- src/parsers/latexparser.cxx.orig	2008-04-23 17:56:27.000000000 +0200
+++ src/parsers/latexparser.cxx	2008-04-23 17:57:00.000000000 +0200
@@ -82,7 +82,7 @@
 	{ { "\\url", NULL } , 1 }
 };
 
-#define PATTERN_LEN (sizeof(PATTERN) / ((sizeof(char *) * 2) + sizeof(int)))
+#define PATTERN_LEN (sizeof(PATTERN) / sizeof(PATTERN[0]))
 
 LaTeXParser::LaTeXParser(const char * wordchars)
 {
