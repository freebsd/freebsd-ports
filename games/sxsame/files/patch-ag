--- loaddata.c.orig	Sun May  5 04:09:25 1996
+++ loaddata.c	Tue Jul 11 21:32:34 2000
@@ -5,6 +5,9 @@
  * Copyleft  (c) 1994-1996  Software Research Academy                   *
  ************************************************************************/
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/param.h>
 #include "config.h"
 #include "sxsame.h"
 
@@ -25,7 +28,7 @@
 DataFile ***data;
 {
 	FILE *fp;
-	char fname[256];
+	char fname[MAXPATHLEN];
 	char buf[256];
 	char str1[256];
 	char str2[256];
@@ -34,11 +37,18 @@
 	char *p;
 	int i;
 
+	if (MAXPATHLEN <= strlen(entry_name)) {
+		fprintf(stderr,"Error: data file name too long.\n");
+		return 0;
+	}
 	strcpy(fname,entry_name);
 	fp = fopen(fname, "r");
 	if(fp == NULL)
 	{
-		sprintf(fname, "%s/%s", SAME_DIR, entry_name);
+		if (MAXPATHLEN <= snprintf(fname, MAXPATHLEN ,"%s/%s", SAME_DIR, entry_name)) {
+			fprintf(stderr,"Error: data file name too long.\n");
+			return 0;
+		}
 		fp = fopen(fname, "r");
 		if(fp == NULL)
 			return(0);
@@ -81,7 +91,7 @@
 char *fname;
 {
 	FILE *fp;
-	char tmpfname[256];
+	char tmpfname[MAXPATHLEN];
 	char buf[256];
 	char str1[256],str2[256];
 	int val, i, j;
@@ -94,7 +104,7 @@
 	{
 		for(j=0;j<5;j++)
 		{
-			data->xpm_data[i][j] == 0;
+			data->xpm_data[i][j] = 0;
 		}
 	}
 	data->bg_data = 0;
@@ -103,7 +113,10 @@
 	fp = fopen(fname,"r");
 	if(fp == NULL)
 	{
-		sprintf(tmpfname, "%s/%s", SAME_DIR, fname);
+		if (MAXPATHLEN <= snprintf(tmpfname, MAXPATHLEN, "%s/%s", SAME_DIR, fname)) {
+			fprintf(stderr,"Error: data file name too long.\n", fname);
+			return -1;
+		}
 		fp = fopen(tmpfname, "r");
 		if(fp == NULL)
 		{
