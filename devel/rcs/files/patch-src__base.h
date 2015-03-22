--- src/base.h.orig	2013-10-20 10:48:18.000000000 +0200
+++ src/base.h	2015-02-24 21:57:04.059371000 +0100
@@ -753,8 +753,7 @@
 int donerewrite (int changed, time_t newRCStime);
 void ORCSclose (void);
 void ORCSerror (void);
-void unexpected_EOF (void)
-  exiting;
+exiting void unexpected_EOF (void);
 void initdiffcmd (struct diffcmd *dc);
 int getdiffcmd (struct fro *finfile, bool delimiter,
                 FILE *foutfile, struct diffcmd *dc);
@@ -829,8 +828,7 @@
                       char datebuf[datesize + zonelenmax]);
 
 /* rcsutil */
-void thank_you_and_goodnight (int const how)
-  exiting;
+exiting void thank_you_and_goodnight (int const how);
 /* These are for ‘thank_you_and_goodnight’.  */
 #define TYAG_ORCSERROR     (1 << 3)
 #define TYAG_DIRTMPUNLINK  (1 << 2)
