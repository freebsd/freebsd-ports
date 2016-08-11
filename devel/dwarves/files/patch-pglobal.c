--- pglobal.c.orig	2016-06-30 19:30:28 UTC
+++ pglobal.c
@@ -8,7 +8,6 @@
  */
 
 #include <argp.h>
-#include <malloc.h>
 #include <search.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -92,7 +91,7 @@ static void extvar__add(const struct var
 		nodep = tsearch(gvar, &tree, extvar__compare);
 		if (nodep == NULL)
 			oom("tsearch");
-		else if (*nodep != gvar)
+		else if (*nodep != gvar) {
 			if (gvar->var->declaration) {
 				gvar->next = (*nodep)->next;
 				(*nodep)->next = gvar;
@@ -100,6 +99,7 @@ static void extvar__add(const struct var
 				gvar->next = *nodep;
 				*nodep = gvar;
 			}
+		}
 	}
 }
 
@@ -315,7 +315,10 @@ int main(int argc, char *argv[])
 		twalk(tree, function_action__walk);
 	}
 
+#if 0
+	/* Our search.h doesn't implement tdestroy; leak for now. */
 	tdestroy(tree, free_node);
+#endif
 	rc = EXIT_SUCCESS;
 out_cus_delete:
 	cus__delete(cus);
