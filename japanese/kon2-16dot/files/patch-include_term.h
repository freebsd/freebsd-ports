--- include/term.h.orig	1997-01-24 16:07:18.000000000 +0900
+++ include/term.h	2012-05-10 00:14:28.771576381 +0900
@@ -36,5 +36,6 @@
 extern void	TermStart(void);	 /* start procesing */
 extern void	TermRestart(int fd);	 /* restart kon (args are read from fd) */
 extern int	masterPty;		 /* master pseudo-tty file descriptor */
+extern int	TermGetNumber(void);
 
 #endif
