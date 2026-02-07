--- uulib/uuscan.c.orig	Tue Mar  2 01:52:27 2004
+++ uulib/uuscan.c	Sun Jul  3 16:50:37 2005
@@ -251,8 +251,9 @@
     /*
      * see if line was terminated with CR. Otherwise, it continues ...
      */
-    c = strlen (ptr);
-    if (c>0 && (ptr[c-1] == '\012' || ptr[c-1] == '\015'))
+    c = strlen (uugen_inbuffer);
+    if (c>0 &&
+	(uugen_inbuffer[c-1] == '\012' || uugen_inbuffer[c-1] == '\015'))
       hadcr = 1;
     else
       hadcr = 0;
@@ -261,6 +262,7 @@
      * strip whitespace
      */
 
+    c = strlen (ptr);
     ptr     += c;
     llength += c;
     while (llength && isspace(*(ptr-1))) {
