--- IG/src/varkon.c.orig	2008-04-23 13:36:40.000000000 -0500
+++ IG/src/varkon.c	2008-04-23 13:40:00.000000000 -0500
@@ -257,14 +257,14 @@
 /*
 ***Open startup_logfile.
 */
-   strcpy(lfname,getenv("VARKON_ROOT"));
+   strcpy(lfname,getenv("VARKON_TMP"));
    strcat(lfname,"/varkon.LOG");
    if ( (startup_logfile=fopen(lfname,"w")) == NULL )
      {
      printf("Can't open startup_logfile %s\n",lfname);
      exit(-1);
      }
-   fprintf(startup_logfile,"VARKON_ROOT is %s\n",getenv("VARKON_ROOT"));
+   fprintf(startup_logfile,"VARKON_TMP is %s\n",getenv("VARKON_TMP"));
    fflush(startup_logfile);
 /*
 ***System is now starting up.
