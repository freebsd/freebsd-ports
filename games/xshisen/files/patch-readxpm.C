
$FreeBSD$

--- readxpm.C.orig	Sun Jul  7 01:34:47 2002
+++ readxpm.C	Thu Sep 15 13:56:38 2005
@@ -12,7 +12,7 @@
   char buffer[1024];
 
   for(int i=0; i<PKIND; i++) {
-    sprintf(buffer, "%s/%s/%s.xpm", directory, subdir, files[i]);
+    snprintf(buffer, sizeof(buffer), "%s/%s/%s.xpm", directory, subdir, files[i]);
     Mp[i].ReadFile(w, buffer, i, globRes.colorCloseness);
   }
 }
