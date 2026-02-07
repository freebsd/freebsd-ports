--- src/parser.y.orig	Sun Aug 15 19:59:37 2004
+++ src/parser.y	Sun Aug 15 20:13:24 2004
@@ -30,6 +30,8 @@
     #include "constant.h"
     #include "variable.h"
 
+    void yyerror(char *error);
+
     guint linecnt;
     gchar *input_str;
     guint curpos;
