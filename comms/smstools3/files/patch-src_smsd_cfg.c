--- src/smsd_cfg.c	Fri Apr 21 11:25:01 2006
+++ src/smsd_cfg.c	Fri Apr 21 11:27:51 2006
@@ -387,7 +387,7 @@
   printf("         -h  this help\n");
   printf("         -s  display status monitor\n");
   printf("         -V  print copyright and version\n\n");
-  printf("All other options are set by the file /etc/smsd.conf.\n\n");
+  printf("All other options are set by the file %%PREFIX%%/etc/smsd.conf.\n\n");
   printf("Output is written to stdout, errors are written to stderr.\n\n");
   exit(0);
 }
@@ -395,7 +395,7 @@
 void parsearguments(int argc,char** argv)
 {
   int result;
-  strcpy(configfile,"/etc/smsd.conf");
+  strcpy(configfile,"%%PREFIX%%/etc/smsd.conf");
   printstatus=0;
 
   do
