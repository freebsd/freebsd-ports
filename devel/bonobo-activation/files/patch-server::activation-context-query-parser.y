
$FreeBSD$

--- server/activation-context-query-parser.y	2002/02/13 17:42:46	1.1
+++ server/activation-context-query-parser.y	2002/02/13 17:42:56
@@ -23,7 +23,7 @@
  */
 
 %{
-#define YYSTACK_USE_ALLOCA
+#define YYSTACK_USE_ALLOCA 1
 
 #include "activation-context-query.h"
 
