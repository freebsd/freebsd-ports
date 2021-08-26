--- ftpd/ftpcmd.y.orig	2004-12-19 18:44:42 UTC
+++ ftpd/ftpcmd.y
@@ -1376,7 +1376,7 @@ static void	 toolong(int);
 #ifdef INET6
 static void	 v4map_data_dest(void);
 #endif
-static int	 yylex(void);
+int	 yylex(void);
 
 static struct tab *
 lookup(struct tab *p, char *cmd)
@@ -1394,7 +1394,7 @@ lookup(struct tab *p, char *cmd)
  * getline - a hacked up version of fgets to ignore TELNET escape codes.
  */
 char *
-getline(char *s, int n, FILE *iop)
+get_line(char *s, int n, FILE *iop)
 {
 	int c;
 	register char *cs;
@@ -1530,7 +1530,7 @@ check_syntax(struct tab *cmd, char *cbuf, size_t cpos)
 	return 1;
 }
 
-static int
+int
 yylex(void)
 {
 	static int cpos;
@@ -1545,7 +1545,7 @@ yylex(void)
 		case CMD:
 			(void) signal(SIGALRM, toolong);
 			(void) alarm(timeout);
-			if (getline(cbuf, sizeof(cbuf)-1, stdin) == NULL) {
+			if (get_line(cbuf, sizeof(cbuf)-1, stdin) == NULL) {
 				reply(221, "You could at least say goodbye.");
 				dologout(0);
 			}
