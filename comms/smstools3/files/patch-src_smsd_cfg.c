--- src/smsd_cfg.c.orig	2009-06-01 12:58:10.000000000 +0200
+++ src/smsd_cfg.c	2009-06-15 09:11:18.000000000 +0200
@@ -1449,7 +1449,7 @@
   printf("         -t  run smsd in terminal\n");
   printf("         -C  Communicate with device\n\n");
   printf("         -V  print copyright and version\n\n");
-  printf("All other options are set by the file /etc/smsd.conf.\n\n");
+  printf("All other options are set by the file %%PREFIX%%/etc/smsd.conf.\n\n");
   printf("Output is written to stdout, errors are written to stderr.\n\n");
   exit(0);
 }
@@ -1459,7 +1459,7 @@
   int result;
   int i;
 
-  strcpy(configfile,"/etc/smsd.conf");
+  strcpy(configfile,"%%PREFIX%%/etc/smsd.conf");
   printstatus=0;
   arg_infofile[0] = 0;
   arg_pidfile[0] = 0;
