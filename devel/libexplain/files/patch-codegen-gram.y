--- codegen/gram.y.orig	2012-11-20 06:20:24.000000000 +0100
+++ codegen/gram.y	2013-02-28 17:27:14.000000000 +0100
@@ -258,7 +258,6 @@
 }
 
 
-static int yyparse(void);
 static node_t *result;
 #if YYDEBUG
 extern int yydebug;
