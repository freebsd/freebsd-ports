--- src/main.c.orig	Thu Jul 15 15:04:36 2004
+++ src/main.c	Thu Jul 15 15:17:57 2004
@@ -284,7 +284,7 @@
 	sprintf(buffer,"%.500s/.dd2rc",getenv("HOME"));
 	if(!loadCFG(buffer,&conf)) {
 		/* if there's no local, use global */
-		sprintf(buffer,"%s/dd2.cfg",DD2_DATA);
+		sprintf(buffer,"%s/dd2.cfg",SYSCONFDIR);
 		if(!loadCFG(buffer,&conf))
 			fprintf(stderr,"unable to read configuration, using defaults\n");
 	}
@@ -295,7 +295,7 @@
 #endif
 
 	/* read hi-scores */
-	sprintf(buffer,"%s/dd2-hiscore",DD2_DATA);
+	sprintf(buffer,"%s/dd2-hiscore",LOCALSTATEDIR);
 	if(!loadScore(buffer,hiscore))
 		fprintf(stderr,"unable to read hi-scores, using defaults\n");
 
@@ -462,7 +462,7 @@
 	saveCFG(buffer,&conf);
 
 	/* save hi-scores */
-	sprintf(buffer,"%s/dd2-hiscore",DD2_DATA);
+	sprintf(buffer,"%s/dd2-hiscore",LOCALSTATEDIR);
 	if(!saveScore(buffer,hiscore))
 		fprintf(stderr,"unable to save hi-scores\ndo you have permissions to write into %s?\n"
 			,buffer);
