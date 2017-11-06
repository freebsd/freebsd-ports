--- runtime/flangrti/iostdinit.c.orig	2017-10-19 11:03:03 UTC
+++ runtime/flangrti/iostdinit.c
@@ -160,7 +160,7 @@ __io_ferror(void *p)
 int
 __io_getfd(void *fp)
 {
-  return (((FILE *)fp)->_fileno);
+  return (((FILE *)fp)->_file);
 }
 
 /* is a tty? */
@@ -270,14 +270,14 @@ extern long *_imp___timezone_dll; /* for crtdll.dll */
 #define timezone _timezone /* cygnus, timezone is usually a function */
 #endif
 
-#elif !defined(DEC) && !defined(IBM) && !defined(ST100_V1_2) &&                !defined(OSX86) /* !defined(WINNT) */
+#elif !defined(DEC) && !defined(IBM) && !defined(ST100_V1_2) &&                !defined(OSX86) && !defined(__FreeBSD__) /* !defined(WINNT) */
 extern time_t timezone; /* for the rest */
 #endif
 
 int
 __io_timezone(void *tm)
 {
-#if defined(SUN4) || defined(PPC) || defined(OSX86)
+#if defined(SUN4) || defined(PPC) || defined(OSX86) || defined(__FreeBSD__)
   return ((struct tm *)tm)->tm_gmtoff;
 #elif defined(WINNT) || defined(WIN64) || defined(WIN32)
   return (0);
