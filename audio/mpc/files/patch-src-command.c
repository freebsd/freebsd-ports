--- src/command.c	Wed Mar  3 19:05:02 2004
+++ src/command.c	Wed Mar  3 19:05:47 2004
@@ -243,16 +243,23 @@
 int cmd_seek ( int argc, char ** argv, mpd_Connection * conn )
 {
 	mpd_Status * status = mpd_getStatus(conn);
+	char * arg = argv[0];
+	int seekmode;
+	char * test;
+	int seekchange;
+	char * last_char;
+	int sec;
+	float perc;
+	int seekto;
+
 	my_finishCommand(conn);
 	if(status->state==MPD_STATUS_STATE_STOP)
 		DIE("not currently playing\n");
 
-	char * arg = argv[0];
-
 	if(!strlen(arg))
 		DIE("\"%s\" is not a positive number\n", arg);
 
-	int seekmode = Absolute;
+	seekmode = Absolute;
 
 	if(arg[0] == '+') {
 		seekmode = RelForward;
@@ -262,15 +269,13 @@
 		arg++;
 	}
 
-	char * test;
-	int seekchange;
 
-	char * last_char = &arg[strlen(arg)-1];
+	last_char = &arg[strlen(arg)-1];
 	if(*last_char == 's') {
 		/* absolute seek (in seconds) */
 
 		*last_char = '\0'; /* chop off the s */
-		int sec = strtol(arg,&test,10); /* get the # of seconds */
+		sec = strtol(arg,&test,10); /* get the # of seconds */
 
 		if(*test!='\0' || sec<0)
 			DIE("\"%s\" is not a positive number\n", arg);
@@ -280,14 +285,14 @@
 	} else {
 		/* percent seek */
 
-		float perc = strtod(arg,&test);
+		perc = strtod(arg,&test);
 		if(*test!='\0' || perc<0 || perc>100)
 			DIE("\"%s\" is not an number between 0 and 100\n",arg);
 
 		seekchange = perc*status->totalTime/100+0.5;
 	}
 
-	int seekto = calculate_seek(status->elapsedTime, seekchange, seekmode);
+	seekto = calculate_seek(status->elapsedTime, seekchange, seekmode);
 
 	if(seekto > status->totalTime)
 		DIE("seek amount would seek past the end of the song\n");
