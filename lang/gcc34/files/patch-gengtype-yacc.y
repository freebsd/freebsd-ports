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
