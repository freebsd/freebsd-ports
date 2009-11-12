--- src/cfg.c.orig	2009-11-12 09:26:15.000000000 +0100
+++ src/cfg.c	2009-11-12 08:33:55.000000000 +0100
@@ -1548,12 +1548,14 @@
     _exit(1);
   }
   if((fdsc=open(cfg->nvram, O_RDONLY|O_NONBLOCK) == -1) && errno == ENOENT) {
+#ifndef __FreeBSD__
     /* Try devfs device */
     if((cfg->nvram=strdup(DEFAULT_NVRAMDEV_DEVFS)) == NULL) {
       fputs(_("Not enough memory"),stderr);
       _exit(1);
     }
     fdsc = open(cfg->nvram, O_RDONLY|O_NONBLOCK);
+#endif
   }
 
   if(fdsc != -1) {
