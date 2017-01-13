--- monetdb5/extras/jaql/parser/jaql.y.orig	2013-01-14 21:06:06.000000000 +0800
+++ monetdb5/extras/jaql/parser/jaql.y	2017-01-09 04:57:50.801797000 +0800
@@ -81,12 +81,10 @@
 
 
 %{
-#define YYLEX_PARAM j->scanner
-
 int jaqllex(YYSTYPE* lvalp, void *scanner);
 
 void
-jaqlerror(struct _jc* j, char const *msg)
+jaqlerror(struct _jc* j, char const *msg, char const *yy_)
 {
 	if (j->err[0] == '\0') {
 		char around[32];
@@ -114,6 +112,8 @@
 
 %}
 
+%parse-param {void *scanner}
+
 %%
 
 stmt: jaql ';'
