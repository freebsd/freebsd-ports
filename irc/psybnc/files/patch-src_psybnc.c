--- src/psybnc.c.orig	2016-06-20 14:41:27 UTC
+++ src/psybnc.c
@@ -44,6 +44,8 @@ int slice=0;
 
 #ifdef HAVE_SSL
 
+int fexists(char *fname);
+
 void initSSL()
 {
     SSL_load_error_strings();
@@ -171,13 +173,17 @@ main (int argc, char **argv)
   if(argc==2)
   {
       strmncpy(configfile,argv[1],sizeof(configfile));
-  } else {
+  } else if (fexists("psybnc.conf")) {
+  		strcpy(configfile, "psybnc.conf");
+  } else if (fexists(PREFIX "/etc/psybnc.conf")) {
       strcpy(configfile,"psybnc.conf");  /* rcsid */
+  } else {
+  		strcpy(configfile, "psybnc.conf");
   }
   conffile=fopen(configfile,"r");
   if(conffile==NULL)
   {
-     printf("Configuration File %s not found, aborting\nRun 'make menuconfig' for creating a configuration or create the file manually.\n",conffile); /* rcsid */
+     printf("Configuration file psybnc.conf not found in current directory or in " PREFIX "/etc/psybnc.conf.\n Copy " PREFIX "/etc/psybnc.conf.sample to the current directory as psybnc.conf :\n        cp " PREFIX "/etc/psybnc.conf.sample psybnc.conf\n\nOR create the file manually.\n"); /* rcsid */
      exit (0x0);
   }
   fclose(conffile);
@@ -302,3 +308,15 @@ main (int argc, char **argv)
   bncmain();
 }
 
+int fexists(char *fname)
+{
+    FILE *fn;
+    int rc=0;
+    fn=fopen(fname,"r");
+    if(fn!=NULL)
+    {
+	fclose(fn);
+	rc=1;
+    }
+    return rc;
+}
