--- uip/popsbr.c.orig	2001-04-02 10:50:01 UTC
+++ uip/popsbr.c
@@ -63,7 +63,7 @@ int	command(), multiline();
 static	int	command(), multiline();
 #endif
 
-static int	getline();
+static int	get_line();
 static putline();
 
 #ifdef NNTP
@@ -176,7 +176,7 @@ int	snoop;
 
     (void) signal (SIGPIPE, SIG_IGN);
 
-    switch (getline (response, sizeof response, input)) {
+    switch (get_line (response, sizeof response, input)) {
 	case OK: 
 	    if (poprint)
 		fprintf (stderr, "<--- %s\n", response);
@@ -619,7 +619,7 @@ char   *fmt,
     if (putline (buffer, output) == NOTOK)
 	return NOTOK;
 
-    switch (getline (response, sizeof response, input)) {
+    switch (get_line (response, sizeof response, input)) {
 	case OK: 
 	    if (poprint)
 		fprintf (stderr, "<--- %s\n", response);
@@ -645,7 +645,7 @@ static int  multiline () {
 #endif
     char    buffer[BUFSIZ + TRMLEN];
 
-    if (getline (buffer, sizeof buffer, input) != OK)
+    if (get_line (buffer, sizeof buffer, input) != OK)
 	return NOTOK;
 #ifdef	DEBUG
     if (poprint)
@@ -665,7 +665,7 @@ static int  multiline () {
 
 /*  */
 
-static int  getline (s, n, iop)
+static int  get_line (s, n, iop)
 char   *s;
 int     n;
 FILE * iop;
