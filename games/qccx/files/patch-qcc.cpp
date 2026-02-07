--- qcc.cpp.orig	Tue Jan 18 17:58:23 2005
+++ qcc.cpp	Tue Jan 18 17:03:34 2005
@@ -542,8 +542,9 @@
 void PR_PrintStatement (dstatement_t *s)
 {
 	int		i;
+	int		opindex;
 
-	for (int opindex = 0 ; pr_opcodes[opindex].op != s->op ; opindex++);
+	for (opindex = 0 ; pr_opcodes[opindex].op != s->op ; opindex++);
 
 	printf ("%4i : %4i : %s ", (int)(s - statements), statement_linenums[s-statements], pr_opcodes[opindex].opname);
 	i = strlen(pr_opcodes[opindex].opname);
@@ -1107,7 +1108,7 @@
 main
 ============
 */
-void main (int argc, char **argv)
+int main (int argc, char **argv)
 {
 	char	*src;
 	char	*src2;
@@ -1135,7 +1136,7 @@
 		printf("\t/Od\teliminate duplicate defs\n");
 		printf("\t/Os\thash lookup in CopyString\n");
 		printf("\t/O2\tuse all optimizations\n");
-		return;
+		return (0);
 	}
 
 	p = CheckParm ("-src");
