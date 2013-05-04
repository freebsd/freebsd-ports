--- actioncompiler/swf5compiler.flex~	2013-03-14 04:53:36.000000000 +0900
+++ actioncompiler/swf5compiler.flex	2013-03-14 04:52:36.000000000 +0900
@@ -5,6 +5,7 @@
 
 #include "compile.h"
 #include "action.h"
+#define YYPARSE_PARAM buffer
 #include "swf5compiler.tab.h" /* defines token types */
 
 int swf5debug;
