--- src/gripcfg.c.orig	2013-05-12 21:29:57.498271858 +0100
+++ src/gripcfg.c	2013-05-12 21:30:09.109272899 +0100
@@ -791,7 +791,7 @@
   };
 
 #ifdef CDPAR
-  if(ripcfg==0) return;
+  if(ripcfg==0) return (0);
 #endif
 
   sprintf(buf,"%s/%s-%s",getenv("HOME"),ginfo->config_filename,
