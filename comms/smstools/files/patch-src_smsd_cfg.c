--- src/smsd_cfg.orig   Sat Nov  6 16:04:24 2004
+++ src/smsd_cfg.c      Sat Nov  6 16:06:29 2004
@@ -329,7 +329,7 @@
   printf("         -h  this help\n");
   printf("         -s  display status monitor\n");
   printf("         -V  print copyright and version\n\n");
-  printf("All other options are set by the file /etc/smsd.conf.\n\n");
+  printf("All other options are set by the file %%PREFIX%%/etc/smsd.conf.\n\n");
   printf("Output is written to stdout, errors are written to stderr.\n\n");
   exit(0);
 }
@@ -337,7 +337,7 @@
 void parsearguments(int argc,char** argv)
 {
   int result;
-  strcpy(configfile,"/etc/smsd.conf");
+  strcpy(configfile,"%%PREFIX%%/etc/smsd.conf");
   debug=0;
   printstatus=0;

