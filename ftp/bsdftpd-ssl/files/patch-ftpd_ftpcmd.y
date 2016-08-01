--- ftpd/ftpcmd.y.orig	2004-12-19 18:44:42 UTC
+++ ftpd/ftpcmd.y
@@ -1394,7 +1394,7 @@ lookup(struct tab *p, char *cmd)
  * getline - a hacked up version of fgets to ignore TELNET escape codes.
  */
 char *
-getline(char *s, int n, FILE *iop)
+get_line(char *s, int n, FILE *iop)
 {
 	int c;
 	register char *cs;
@@ -1545,7 +1545,7 @@ yylex(void)
 		case CMD:
 			(void) signal(SIGALRM, toolong);
 			(void) alarm(timeout);
-			if (getline(cbuf, sizeof(cbuf)-1, stdin) == NULL) {
+			if (get_line(cbuf, sizeof(cbuf)-1, stdin) == NULL) {
 				reply(221, "You could at least say goodbye.");
 				dologout(0);
 			}
