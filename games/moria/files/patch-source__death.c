$FreeBSD$

--- source/death.c.orig	Thu Aug  7 16:02:45 2003
+++ source/death.c	Thu Aug  7 16:06:12 2003
@@ -123,6 +123,7 @@
 #include <stdlib.h>
 #endif
 
+#ifndef __FreeBSD__
 #ifndef VMS
 #ifndef MAC
 #if !defined(ATARIST_MWC) && !defined(AMIGA)
@@ -130,18 +131,19 @@
 #endif
 #endif
 #endif
+#endif
 
 static void date(day)
 char *day;
 {
   register char *tmp;
-#ifdef MAC
+#if defined(MAC) || defined(__FreeBSD__)
   time_t clockvar;
 #else
   long clockvar;
 #endif
 
-#ifdef MAC
+#if defined(MAC) || defined(__FreeBSD__)
   clockvar = time((time_t *) 0);
 #else
   clockvar = time((long *) 0);
