$FreeBSD$

--- source/main.c.orig	Thu Jul 21 19:47:27 1994
+++ source/main.c	Thu Aug  7 16:12:13 2003
@@ -88,6 +88,7 @@
 #include <time.h>
 #endif
 
+#ifndef __FreeBSD__
 #ifndef VMS
 #ifndef MAC
 #ifndef GEMDOS
@@ -98,6 +99,9 @@
 char *getenv();
 #endif
 #endif
+#else
+#include <stdlib.h>
+#endif
 
 #ifndef MAC
 #ifndef AMIGA
@@ -360,7 +364,7 @@
   else
     {	  /* Create character	   */
       create_character();
-#ifdef MAC
+#if defined(MAC) || defined(__FreeBSD__)
       birth_date = time ((time_t *)0);
 #else
       birth_date = time ((long *)0);
