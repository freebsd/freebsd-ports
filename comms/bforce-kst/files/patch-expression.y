--- bforce/expression.y.old	Thu Aug 30 16:33:48 2001
+++ bforce/expression.y	Thu Feb  6 23:38:32 2003
@@ -52,6 +52,7 @@
 #include "logger.h"
 #include "session.h"
 #include "nodelist.h"
+#include "io.h"
 
 static struct tm *now    = NULL;
 static int   expr_result = 0;
@@ -205,6 +206,7 @@
 	{
 		$$ = expr_check_logic($1, OR, $3);
 	}
+	;
 %%
 
 #include "expression_lex.c"
@@ -329,6 +331,10 @@
 	else if( state.modemport && state.modemport->name )
 	{
 		return strstr(state.modemport->name, str) ? 1 : 0;
+	}
+	else if( isatty(0) )
+	{
+		return strstr(ttyname(0), str) ? 1 : 0;
 	}
 	
 	return -1;
