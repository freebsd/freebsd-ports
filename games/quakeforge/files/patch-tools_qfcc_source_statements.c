--- tools/qfcc/source/statements.c.orig	2013-01-23 03:10:55 UTC
+++ tools/qfcc/source/statements.c
@@ -1306,8 +1306,11 @@ move_labels (sblock_t *dst, sblock_t *sr
 
 	if (!src_labels)
 		return;
-	while (src_labels->next)
+	src_labels->dest = dst;
+	while (src_labels->next) {
 		src_labels = src_labels->next;
+		src_labels->dest = dst;
+	}
 	src_labels->next = dst->labels;
 	dst->labels = src->labels;
 	src->labels = 0;
