--- lib/scanargs.c.orig	Thu Mar 10 21:23:06 2005
+++ lib/scanargs.c	Thu Mar 10 21:25:26 2005
@@ -128,10 +128,10 @@
 va_list argl;
 {
 
-    register    check;			/* check counter to be sure all argvs
+    register int  check;		/* check counter to be sure all argvs
 					   are processed */
     register CONST_DECL char  *cp;
-    register    cnt;
+    register int  cnt;
     int	    optarg = 0;			/* where optional args start */
     int	    nopt = 0;
     char    tmpflg,			/* temp flag */
