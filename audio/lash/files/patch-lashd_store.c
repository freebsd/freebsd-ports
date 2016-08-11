--- lashd/store.c.orig	2007-01-13 22:08:54 UTC
+++ lashd/store.c
@@ -36,6 +36,31 @@
 
 #define STORE_INFO_FILE ".store_info"
 
+ssize_t
+getline (char **lineptr, size_t *n, FILE *stream)
+{
+        int linelen;
+
+        char *line=fgetln(stream, &linelen);
+
+        if (line==NULL) {
+                *lineptr=NULL;
+                return -1;
+        }
+
+        if (linelen + 1 > *n ) {
+                *lineptr=realloc(*lineptr, linelen + 1);
+                *n=linelen + 1;
+
+                if (lineptr==NULL)
+                        return -1;
+        }
+
+        strlcpy(*lineptr, line, linelen + 1);
+
+        return linelen;
+}
+
 void
 store_free(store_t * store)
 {
