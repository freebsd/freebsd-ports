$FreeBSD$

--- source/misc1.c.orig	Thu Aug  7 16:07:21 2003
+++ source/misc1.c	Thu Aug  7 16:08:58 2003
@@ -28,7 +28,7 @@
 #endif
 #endif
 
-#if !defined(ATARIST_MWC) && !defined(MAC) && !defined(VMS) && !defined(AMIGA)
+#if !defined(ATARIST_MWC) && !defined(MAC) && !defined(VMS) && !defined(AMIGA) && !defined(__FreeBSD__)
 long time();
 #endif
 struct tm *localtime();
@@ -45,7 +45,7 @@
   register int32u clock_var;
 
   if (seed == 0)
-#ifdef MAC
+#if defined(MAC) || defined(__FreeBSD__)
     clock_var = time((time_t *)0);
 #else
     clock_var = time((long *)0);
@@ -89,10 +89,14 @@
 int check_time()
 {
 #ifdef MORIA_HOU
+#if defined(MAC) || defined(__FreeBSD__)
+  time_t clock_var;
+#else
   long clock_var;
+#endif
   register struct tm *tp;
 
-#ifdef MAC
+#if defined(MAC) || defined(__FreeBSD__)
   clock_var = time((time_t *)0);
 #else
   clock_var = time((long *)0);
