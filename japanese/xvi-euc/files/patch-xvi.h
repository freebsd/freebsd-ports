
$FreeBSD$

--- xvi.h.orig	Wed Dec 18 20:45:08 2002
+++ xvi.h	Wed Dec 18 20:45:25 2002
@@ -90,9 +90,9 @@
  * Functions which ANSI does not specify should
  * be included in any standard header file.
  */
+#ifndef BSD386	/* ken */
 extern	int	chdir P((const char *path));
 extern	char	*getcwd P((char *, unsigned));
-#ifndef BSD386	/* ken */
 extern	void	sleep P((unsigned seconds));
 #endif
 
