--- src/rip.c.orig	Fri Apr 12 11:53:29 2002
+++ src/rip.c	Wed Jul 24 01:49:30 2002
@@ -980,7 +980,7 @@
     else strncpy(res,_("NoTitle"),PATH_MAX);
     break;
   case 'i':
-    g_snprintf(res,PATH_MAX,"%02x",enc_track->discid);
+    g_snprintf(res,PATH_MAX,"%08x",enc_track->discid);
     *munge=FALSE;
     break;
   case 'y':
