--- syscall.c	Mon Jan 26 10:37:06 2004
+++ syscall.c	Mon Jan 26 10:40:55 2004
@@ -510,9 +510,13 @@
 f_ctime(void)
 {
     long        timev;
+    time_t	timet;
     string_t    *s;
 
-    if (ici_typecheck("i", &timev) || (s = new_cname(ctime(&timev))) == NULL)
+    if (ici_typecheck("i", &timev))
+	return 1;
+    timet = timev;
+    if ((s = new_cname(ctime(&timet))) == NULL)
         return 1;
     return ici_ret_with_decref(objof(s));
 }
