--- pager.h.orig	1997-06-12 11:59:28 UTC
+++ pager.h
@@ -67,7 +67,7 @@ typedef struct {
 /*{{{	utility */
 extern char	*skip (char *str);
 extern char	*skipch (char *str, char ch);
-extern char	*getline (FILE *fp, Bool cont);
+extern char	*get_line (FILE *fp, Bool cont);
 extern int	verbose_out (char *, ...);
 /*}}}*/
 /*{{{	string handling */
