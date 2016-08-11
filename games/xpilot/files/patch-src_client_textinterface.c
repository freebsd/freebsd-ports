--- src/client/textinterface.c.orig	2010-02-21 15:59:29 UTC
+++ src/client/textinterface.c
@@ -75,7 +75,7 @@ extern char		hostname[];		/* my local ho
 /*
  * just like fgets() but strips newlines like gets().
  */
-static char* getline(char* buf, int len, FILE* stream)
+static char* get_line(char* buf, int len, FILE* stream)
 {
     char		*nl;
 
@@ -305,7 +305,7 @@ static bool Process_commands(sockbuf_t *
 	else if (!auto_connect) {
 	    printf("*** Server on %s. Enter command> ", conpar->server_name);
 
-	    getline(linebuf, MAX_LINE-1, stdin);
+	    get_line(linebuf, MAX_LINE-1, stdin);
 	    if (feof(stdin)) {
 		puts("");
 		c = 'Q';
@@ -385,7 +385,7 @@ static bool Process_commands(sockbuf_t *
 	    case 'K':
 		printf("Enter name of victim: ");
 		fflush(stdout);
-		if (!getline(linebuf, MAX_LINE-1, stdin)) {
+		if (!get_line(linebuf, MAX_LINE-1, stdin)) {
 		    printf("Nothing changed.\n");
 		    continue;
 		}
@@ -396,7 +396,7 @@ static bool Process_commands(sockbuf_t *
 	    case 'R':
 		printf("Enter maximum number of robots: ");
 		fflush(stdout);
-		if (!getline(linebuf, MAX_LINE-1, stdin)) {
+		if (!get_line(linebuf, MAX_LINE-1, stdin)) {
 		    printf("Nothing changed.\n");
 		    continue;
 		}
@@ -410,7 +410,7 @@ static bool Process_commands(sockbuf_t *
 	    case 'M':				/* Send a message to server. */
 		printf("Enter message: ");
 		fflush(stdout);
-		if (!getline(linebuf, MAX_LINE-1, stdin) || !linebuf[0]) {
+		if (!get_line(linebuf, MAX_LINE-1, stdin) || !linebuf[0]) {
 		    printf("No message sent.\n");
 		    continue;
 		}
@@ -425,7 +425,7 @@ static bool Process_commands(sockbuf_t *
 	    case 'D':				/* Shutdown */
 		if (!auto_shutdown) {
 		    printf("Enter delay in seconds or return for cancel: ");
-		    getline(linebuf, MAX_LINE-1, stdin);
+		    get_line(linebuf, MAX_LINE-1, stdin);
 		    /*
 		     * No argument = cancel shutdown = arg_int=0
 		     */
@@ -436,7 +436,7 @@ static bool Process_commands(sockbuf_t *
 			    delay = 1;
 
 		    printf("Enter reason: ");
-		    getline(linebuf, MAX_LINE-1, stdin);
+		    get_line(linebuf, MAX_LINE-1, stdin);
 		} else {
 		    strlcpy(linebuf, shutdown_reason, sizeof(linebuf));
 		    delay = 60;
@@ -448,7 +448,7 @@ static bool Process_commands(sockbuf_t *
 	    case 'O':				/* Tune an option. */
 		printf("Enter option: ");
 		fflush(stdout);
-		if (!getline(linebuf, MAX_LINE-1, stdin)
+		if (!get_line(linebuf, MAX_LINE-1, stdin)
 		    || (len=strlen(linebuf)) == 0) {
 		    printf("Nothing changed.\n");
 		    continue;
@@ -456,7 +456,7 @@ static bool Process_commands(sockbuf_t *
 		printf("Enter new value for %s: ", linebuf);
 		fflush(stdout);
 		strcat(linebuf, ":"); len++;
-		if (!getline(&linebuf[len], MAX_LINE-1-len, stdin)
+		if (!get_line(&linebuf[len], MAX_LINE-1-len, stdin)
 		    || linebuf[len] == '\0') {
 		    printf("Nothing changed.\n");
 		    continue;
@@ -516,7 +516,7 @@ static bool Process_commands(sockbuf_t *
 	    case 'T':				/* Set team. */
 		printf("Enter team: ");
 		fflush(stdout);
-		if (!getline(linebuf, MAX_LINE-1, stdin)
+		if (!get_line(linebuf, MAX_LINE-1, stdin)
 		    || (len = strlen(linebuf)) == 0) {
 		    printf("Nothing changed.\n");
 		}
