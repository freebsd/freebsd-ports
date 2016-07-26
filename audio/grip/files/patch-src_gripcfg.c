--- src/gripcfg.c.orig	2005-06-25 18:00:55 UTC
+++ src/gripcfg.c
@@ -791,7 +791,7 @@ gboolean LoadRipperConfig(GripInfo *ginf
   };
 
 #ifdef CDPAR
-  if(ripcfg==0) return;
+  if(ripcfg==0) return (0);
 #endif
 
   sprintf(buf,"%s/%s-%s",getenv("HOME"),ginfo->config_filename,
