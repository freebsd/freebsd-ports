--- gcc/gengtype-yacc.y.orig	Fri Sep 20 00:33:24 2002
+++ gcc/gengtype-yacc.y	Tue Apr 22 09:11:27 2003
@@ -24,6 +24,9 @@
 #include "system.h"
 #include "gengtype.h"
 #define YYERROR_VERBOSE
+
+#define malloc xmalloc
+#define realloc xrealloc
 %}
 
 %union {
@@ -37,11 +40,11 @@
 %token <t>ENT_STRUCT
 %token ENT_EXTERNSTATIC
 %token ENT_YACCUNION
-%token GTY_TOKEN "GTY"
-%token UNION "union"
-%token STRUCT "struct"
-%token ENUM "enum"
-%token ALIAS "ptr_alias"
+%token GTY_TOKEN
+%token UNION
+%token STRUCT
+%token ENUM
+%token ALIAS
 %token <s>PARAM_IS
 %token NUM
 %token PERCENTPERCENT "%%"
