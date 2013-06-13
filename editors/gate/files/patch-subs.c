diff --git subs.c subs.c
index 287d9d3..a6caea9 100644
--- subs.c
+++ subs.c
@@ -429,7 +429,7 @@ int cliplast(char *lastbuf, int bufsize)
 #endif
 
     /* Make a copy of the file */
-    if ((cfp= make_copy()) == NULL) return;
+    if ((cfp= make_copy()) == NULL) return 0;
     fflush(cfp);
     fseek(cfp,0L,0);
 
