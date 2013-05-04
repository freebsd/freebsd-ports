--- actioncompiler/swf4compiler.flex~	2002-06-24 21:21:54.000000000 +0900
+++ actioncompiler/swf4compiler.flex	2013-03-14 04:49:15.000000000 +0900
@@ -5,6 +5,7 @@
 
 #include "compile.h"
 #include "action.h"
+#define YYPARSE_PARAM buffer
 #include "swf4compiler.tab.h" /* defines token types */
 
 int swf4debug;
