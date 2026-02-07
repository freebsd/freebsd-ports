--- pr_comp.cpp.orig	Tue Jan 18 17:58:23 2005
+++ pr_comp.cpp	Tue Jan 18 17:02:25 2005
@@ -812,7 +812,7 @@
 		PR_Statement(&pr_opcodes[OP_IFNOT], e, 0);
 		patch1 = &statements[numstatements-1];
 		PR_ParseStatement();
-		for (i = 0 ; i < numtemp ; i++)
+		for (int i = 0 ; i < numtemp ; i++)
 		{
 			statement_linenums[numstatements] = linenum[i];
 			statements[numstatements++] = temp[i];
