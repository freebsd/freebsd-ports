--- src/cfg.c.orig	2005-07-18 14:15:59 UTC
+++ src/cfg.c
@@ -1548,12 +1548,14 @@ void find_nvram(config *cfg) /* {{{ */
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
