--- lib/scanargs.c.orig	Thu Feb 27 16:18:15 1992
+++ lib/scanargs.c	Thu Nov 29 23:22:40 2007
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
@@ -408,7 +408,8 @@
 				 * Copy the string so we remain nondestructive
 				 */
 				s = NEW( char, strlen(argp)+1 );
-				strcpy( s, argp );
+				strncpy( s, argp, sizeof(s)-1 );
+				s[sizeof(s) - 1] = '\0';
 				argp = s;
 
 				/* 
