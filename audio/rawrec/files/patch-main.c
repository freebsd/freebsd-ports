--- main.c.orig	Wed May 10 17:27:08 2006
+++ main.c	Wed May 10 17:30:21 2006
@@ -14,6 +14,12 @@
 
 #include "rawrec.h"
 
+size_t strnlen (const char *string, size_t maxlen)
+{
+    const char *end = memchr (string, '\0', maxlen);
+    return end ? (size_t) (end - string) : maxlen;
+}
+
 int main(int argc, char *argv[])
 {
   /* Action for ignoring signals we don't want to deal with.  */
