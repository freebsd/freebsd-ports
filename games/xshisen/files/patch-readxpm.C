
$FreeBSD$

--- readxpm.C.orig
+++ readxpm.C
@@ -12,7 +12,7 @@
   char buffer[1024];
 
   for(int i=0; i<PKIND; i++) {
-    sprintf(buffer, "%s/%s.xpm", directory, files[i]);
+    snprintf(buffer, sizeof(buffer), "%s/%s.xpm", directory, files[i]);
     Mp[i].ReadFile(w, buffer, i, globRes.colorCloseness);
   }
 }
