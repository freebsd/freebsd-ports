--- strings.c.orig	2012-03-20 16:17:25 UTC
+++ strings.c
@@ -39,7 +39,10 @@ void strings__delete(struct strings *sel
 {
 	if (self == NULL)
 		return;
+#if 0
+	/* Our search.h doesn't implement tdestroy; leak for now. */
 	tdestroy(self->tree, do_nothing);
+#endif
 	__gobuffer__delete(&self->gb);
 	free(self);
 }
