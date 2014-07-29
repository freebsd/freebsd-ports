--- src/main.c.orig	Wed Jun  5 17:30:39 2002
+++ src/main.c	Thu Jul  3 18:34:19 2003
@@ -33,7 +33,7 @@
 main(int argc, char **argv)
 {
 	Word *w;
-	char *s, *temp;
+	char *s;
 	char *files[256], **f = files, **ff;
 	int sflag = 0;
 	int i;
@@ -41,6 +41,8 @@
 	Biobuf tb;
 	Bufblock *buf;
 	Bufblock *whatif;
+	char TMPLATE[14];
+	(void)strncpy(TMPLATE,"/tmp/mk.XXXXX", sizeof(TMPLATE));
 
 	/*
 	 *  start with a copy of the current environment variables
@@ -133,21 +135,15 @@
 	/*
 		assignment args become null strings
 	*/
-	temp = 0;
 	for(i = 0; argv[i]; i++) if(utfrune(argv[i], '=')){
 		bufcpy(buf, argv[i], strlen(argv[i]));
 		insert(buf, ' ');
 		if(tfd < 0){
-			temp = maketmp();
-			if(temp == 0) {
-				perror("temp file");
-				Exit();
-			}
-			close(create(temp, OWRITE, 0600));
-			if((tfd = open(temp, 2)) < 0){
-				perror(temp);
+			if ((tfd = mkstemp(TMPLATE)) < 0){
+				perror(TMPLATE);
 				Exit();
 			}
+			unlink(TMPLATE);
 			Binit(&tb, tfd, OWRITE);
 		}
 		Bprint(&tb, "%s\n", argv[i]);
@@ -157,7 +153,6 @@
 		Bflush(&tb);
 		LSEEK(tfd, 0L, 0);
 		parse("command line args", tfd, 1);
-		remove(temp);
 	}
 
 	if (buf->current != buf->start) {
