--- idlc/source/parser.y.orig	2019-08-14 17:32:51 UTC
+++ idlc/source/parser.y
@@ -25,6 +25,7 @@
  * parser.yy - BISON grammar for IDLC 1.0
  */
 
+%define parse.error verbose
 %{
 #include <string.h>
 
@@ -103,7 +104,6 @@
 using namespace ::rtl;
 
 #define YYDEBUG 1
-#define YYERROR_VERBOSE 1
 
 extern int yylex(void);
 void yyerror(char const *);
