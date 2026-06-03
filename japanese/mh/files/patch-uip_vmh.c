--- uip/vmh.c.orig	2001-04-21 11:16:49 UTC
+++ uip/vmh.c
@@ -42,6 +42,10 @@ static char ident[] = "@(#)$Id: vmh.c,v 1.20 1993/08/2
 #endif
 #undef	OK			/* tricky */
 #ifdef	TERMINFO
+#include <sys/param.h>
+#if defined(__FreeBSD__) && __FreeBSD_version > 1500068
+#define NCURSES_INTERNALS
+#endif
 #include <term.h>	/* variables describing terminal capabilities */
 #if defined(HAVE_TCGETATTR) && !defined(TCGETATTR)
 #define TCGETATTR
@@ -115,6 +119,13 @@ void     __cputchar __P((int));
 
 
 #define	XYZ			/* XXX */
+
+#if defined(__FreeBSD__) && __FreeBSD__ >= 5
+struct ldat
+{
+	unsigned long	*text;
+};
+#endif
 
 /*  */
 
