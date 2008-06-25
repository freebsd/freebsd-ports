--- regex.c.orig	2008-06-26 01:17:14.000000000 +0400
+++ regex.c	2008-06-26 01:18:42.000000000 +0400
@@ -3169,6 +3169,11 @@
   if (startpos < 0  ||  startpos > size)
     return -1;
 
+  if (!string) {
+    if (size == 0) string = "";
+    else return -1;
+  }
+
   /* Update the fastmap now if not correct already.  */
   if (fastmap && !bufp->fastmap_accurate) {
     re_compile_fastmap(bufp);
