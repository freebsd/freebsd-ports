--- ufraw_conf.c.orig	2016-11-13 04:00:05 UTC
+++ ufraw_conf.c
@@ -138,7 +138,7 @@ const conf_data conf_default = {
 #elif HAVE_GIMP_2_4
     "gimp", /* remoteGimpCommand */
 #else
-    "gimp-remote", /* remoteGimpCommand */
+    "gimp", /* remoteGimpCommand */
 #endif
 
     /* EXIF data */
