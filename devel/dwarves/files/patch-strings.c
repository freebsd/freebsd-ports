--- strings.c.orig	2016-06-30 19:30:28 UTC
+++ strings.c
@@ -39,7 +39,10 @@ void strings__delete(struct strings *str
 {
 	if (strs == NULL)
 		return;
+#if 0
+	/* Our search.h doesn't implement tdestroy; leak for now. */
 	tdestroy(strs->tree, do_nothing);
+#endif
 	__gobuffer__delete(&strs->gb);
 	free(strs);
 }
