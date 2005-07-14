
$FreeBSD$

--- src/pinfile.c.orig
+++ src/pinfile.c
@@ -21,6 +21,17 @@
 #include <limits.h>
 #include <ctype.h>
 
+char* strndup(const char *str, size_t len) {
+  size_t copy_len=(strlen (str) > len) ? strlen(str): len;
+  char *new = (char *) malloc (copy_len + 1);
+
+  if (new == NULL)
+    return NULL;
+
+  new[copy_len] = '\0';
+  return (char *) memcpy (new, str, copy_len);
+}
+
 char* pinfile_get_data (char* filename) {
   int fd = open(filename,O_RDONLY);
   struct stat fdstat;
