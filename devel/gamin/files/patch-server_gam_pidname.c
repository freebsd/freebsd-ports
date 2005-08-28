--- server/gam_pidname.c.orig	Wed Aug 10 00:00:18 2005
+++ server/gam_pidname.c	Wed Aug 10 00:00:47 2005
@@ -7,9 +7,9 @@
 
 char *gam_get_pidname (int pid)
 {
+    gchar *pidname = NULL;
 #ifdef HAVE_LINUX
     gchar *procname;
-    gchar *pidname = NULL;
     FILE *fp;
 #endif
 
