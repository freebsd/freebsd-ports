--- hiscore.c.orig	Sun May  5 04:09:25 1996
+++ hiscore.c	Tue Jul 11 21:29:01 2000
@@ -5,14 +5,16 @@
  * Copyleft  (c) 1994-1996  Software Research Academy                   *
  ************************************************************************/
 #include <stdio.h>
-#include <sys/types.h>
-#include <sys/stat.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+#include <sys/param.h>
 #include "config.h"
 #include "hiscore.h"
 
 static struct Hiscore hiscore[4];
 
-static char *lockf = LOCK_FILE;
+static char *lockfn = LOCK_FILE;
 static char *hiscoref = HISCORE_FILE;
 extern char *same_dir;
 static int lock_file(
@@ -30,12 +32,15 @@
 	FILE *fp;
 	int i, j;
 	char *myname;
-	char tmpf[256];
+	char tmpf[MAXPATHLEN];
 	int new = 0;
 
 	myname = (char *)getenv("LOGNAME");
-	sprintf(tmpf, "%s/%s", same_dir, hiscoref);
-	umask(0);
+	if (MAXPATHLEN <= snprintf(tmpf, MAXPATHLEN ,"%s/%s", same_dir, hiscoref) ) {
+		fprintf(stderr,"Error: hiscore file name too long.\n");
+		return -1;
+	}
+	umask(002);
 	fp = fopen(tmpf,"rb");
 	if(fp != NULL)
 	{
@@ -75,11 +80,11 @@
 				break;
 			}
 		}
-		if(i < 10 | new == 1)
+		if(i < 10 || new == 1)
 		{
 			if(lock_file(0) != 0)
 				return(-1);
-			umask(0);
+			umask(002);
 			fp = fopen(tmpf, "wb");
 			fwrite(hiscore, sizeof(hiscore), 1, fp);
 			fclose(fp);
@@ -95,10 +100,12 @@
 int cmd;
 {
 	FILE *fp;
-	char lkf[256];
+	char lkf[MAXPATHLEN];
 	int i;
-
-	sprintf(lkf,"%s/%s", same_dir, lockf);
+	if (MAXPATHLEN <= snprintf(lkf, MAXPATHLEN, "%s/%s", same_dir, lockfn)) { 
+		fprintf(stderr,"Error: lock file name too long.\n");
+		return -1;
+	}
 	if(cmd == 1)
 	{
 		if(remove(lkf) != 0)
@@ -134,9 +141,12 @@
 struct Hiscore *hi;
 {
 	FILE *fp;
-	char tmpf[256];
+	char tmpf[MAXPATHLEN];
 
-	sprintf(tmpf, "%s/%s", same_dir, hiscoref);
+	if (MAXPATHLEN <= snprintf(tmpf, MAXPATHLEN, "%s/%s", same_dir, hiscoref)) {
+		fprintf(stderr,"Error: hiscore file name too long.\n");
+		return -1;
+	}
 	fp = fopen(tmpf,"rb");
 	if(fp == NULL)
 		return(-1);
