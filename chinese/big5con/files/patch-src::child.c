--- src/child.c.orig	Mon Apr 15 09:47:23 1996
+++ src/child.c	Tue Nov 26 11:29:49 2002
@@ -22,6 +22,7 @@
 #include	<unistd.h>
 #ifdef __FreeBSD__
 #include        <errno.h>
+#include	<sys/ioctl.h>
 #endif
 
 #include	<getcap.h>
@@ -77,6 +78,9 @@
 {
 	char	*shell, *tail, *tcap;
 	char	buff[80];
+#if defined(__FreeBSD__)
+	struct winsize win;
+#endif
 
 	setgid(getgid());
 	setuid(getuid());
@@ -87,7 +91,11 @@
 	sprintf(buff, "TERMCAP=:co#%d:li#%d:tc=console:",
 		dInfo.txmax + 1, dInfo.tymax + 1);
 #elif defined(__FreeBSD__)
-    sprintf(buff,"TERM=vt100");
+    	win.ws_row = dInfo.tymax + 1;
+	win.ws_col = dInfo.txmax + 1;
+	win.ws_xpixel = win.ws_ypixel = 0;
+	ioctl(STDIN_FILENO, TIOCSWINSZ, &win);
+	sprintf(buff,"TERM=vt100");
 #endif
 	tcap = strdup(buff);
 	putenv(tcap);
@@ -106,7 +114,7 @@
 #if defined(linux)
 	       *(ttyname(fileno(errfp))+8));
 #elif defined(__FreeBSD__)
-	       *(ttyname(fileno(errfp))+9));
+	       ttyname(fileno(errfp)) ? *(ttyname(fileno(errfp))+9) : '?');
 #endif
 	fflush(stdout);
 
