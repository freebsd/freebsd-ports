--- tcap.c.orig	2013-12-12 17:16:34.000000000 +0100
+++ tcap.c	2013-12-12 17:17:40.000000000 +0100
@@ -41,11 +41,12 @@ char *UP, PC, *CM, *CE, *CL, *SO, *SE, *
 
 #ifdef BSD
 #include <sys/ioctl.h>
+#ifdef TIOCGWINSZ
 struct winsize ttysize;
-#endif /* BSD */
-#ifdef ULTRIX
-struct winsize ttysize;
+#else
+struct ttysize ttysize;
 #endif
+#endif /* BSD */
 
 void
 putpad (str)
@@ -62,9 +63,6 @@ tcapopen ()
     char tcbuf[1024];
     char *tv_stype;
     char err_str[NCOL];
-#ifdef ULTRIX
-    struct winsize ttysize;
-#endif
 
     nrow = NROW;
 
@@ -89,7 +87,7 @@ tcapopen ()
 
 
 #ifdef BSD
-#ifdef ULTRIX
+#ifdef TIOCGWINSZ
     if (ioctl (0, TIOCGWINSZ, &ttysize) == 0
 	&& ttysize.ws_row > 0)
     {
@@ -103,7 +101,7 @@ tcapopen ()
 	nrow = ttysize.ts_lines;
     }
     else
-#endif /* ULTRIX */
+#endif /* TIOCGWINSZ */
 #endif /* BSD */
 
 #ifndef OS2
