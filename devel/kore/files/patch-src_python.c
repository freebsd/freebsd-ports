--- src/python.c.orig	2023-11-17 22:08:08 UTC
+++ src/python.c
@@ -4828,7 +4828,7 @@ pyhttp_iterobj_next(struct pyhttp_iterobj *iterobj)
 	}
 
 	kore_buf_reset(&iterobj->buf);
-	kore_buf_appendf(&iterobj->buf, "%lx\r\n", length);
+	kore_buf_appendf(&iterobj->buf, "%zx\r\n", length);
 	kore_buf_append(&iterobj->buf, ptr, length);
 	kore_buf_appendf(&iterobj->buf, "\r\n");
 
