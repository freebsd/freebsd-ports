--- bwbasic.c.orig	Mon Jun  3 17:28:28 2002
+++ bwbasic.c	Mon Jun  3 17:33:08 2002
@@ -32,6 +32,7 @@
 /* NOTE: Modifications marked "JBV" were made by Jon B. Volkoff, */
 /* 11/1995 (eidetics@cerf.net).                                  */
 /*---------------------------------------------------------------*/
+/* Modifications marked (GAW) were made by Garrett Wollman 2002-06-03 */
 
 #include <stdio.h>
 #include <ctype.h>
@@ -51,7 +52,7 @@
 char *bwb_ebuf;				/* error buffer */
 static char *read_line;
 int bwb_trace = FALSE;
-FILE *errfdevice = stderr;              /* output device for error messages */
+FILE *errfdevice /* = stderr (GAW) */;  /* output device for error messages */
 
 #if HAVE_LONGJUMP
 jmp_buf mark;
@@ -133,6 +134,7 @@
    static char end_buf[] = "\0";
 #endif
 
+   errfdevice = stderr;		/* XXX will just get overwritten below? (GAW)*/
 #if INTENSIVE_DEBUG
    prn_xprintf( stderr, "Memory Allocation Statistics:\n" );
    prn_xprintf( stderr, "----------------------------\n" );
