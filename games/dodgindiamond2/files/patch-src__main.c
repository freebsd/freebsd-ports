--- src/main.c.orig	2007-08-14 18:59:42 UTC
+++ src/main.c
@@ -285,7 +285,7 @@ main (int argc, char *argv[])
 	sprintf(buffer,"%.500s/.dd2rc",getenv("HOME"));
 	if(!loadCFG(buffer,&conf)) {
 		/* if there's no local, use global */
-		sprintf(buffer,"%s/dd2.cfg",DD2_DATA);
+		sprintf(buffer,"%s/dd2.cfg",SYSCONFDIR);
 		if(!loadCFG(buffer,&conf))
 			fprintf(stderr,"unable to read configuration, using defaults\n");
 	}
@@ -296,7 +296,7 @@ main (int argc, char *argv[])
 #endif
 
 	/* read hi-scores */
-	sprintf(buffer,"%s/dd2-hiscore",DD2_DATA);
+	sprintf(buffer,"%s/dd2-hiscore",LOCALSTATEDIR);
 	if(!loadScore(buffer,hiscore))
 		fprintf(stderr,"unable to read hi-scores, using defaults\n");
 
@@ -463,7 +463,7 @@ main (int argc, char *argv[])
 	saveCFG(buffer,&conf);
 
 	/* save hi-scores */
-	sprintf(buffer,"%s/dd2-hiscore",DD2_DATA);
+	sprintf(buffer,"%s/dd2-hiscore",LOCALSTATEDIR);
 	if(!saveScore(buffer,hiscore))
 		fprintf(stderr,"unable to save hi-scores\ndo you have permissions to write into %s?\n"
 			,buffer);
