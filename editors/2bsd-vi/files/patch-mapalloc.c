--- /tmp/mapmalloc.c	Mon Jul 12 16:28:16 2004
+++ mapmalloc.c	Mon Jul 12 16:28:37 2004
@@ -550,14 +550,6 @@
 	return NULL;
 }
 
-/*ARGSUSED*/
-char *
-valloc(size)
-size_t size;
-{
-	return NULL;
-}
-
 char *
 mallinfo()
 {
