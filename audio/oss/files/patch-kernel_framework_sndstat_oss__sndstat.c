Thanks to dim@

Clang 19 has become more strict about erroneous redeclarations, which
results in an error building audio/oss:

  oss_sndstat.c:114:17: error: redeclaration of 'version' with a different type: 'char[]' vs 'const char[]'
    114 |     extern char version[];
        |                 ^
  /usr/include/sys/systm.h:54:19: note: previous declaration is here
     54 | extern const char version[];    /* system version */
        |                   ^

Since version[] has been a const char for quite a while now, adjust the
redeclaration in oss_sndstat.c. Note that it also might be deleted
entirely, since the file already includes <sys/systm.h>.

--- kernel/framework/sndstat/oss_sndstat.c.orig	2024-10-17 19:27:09 UTC
+++ kernel/framework/sndstat/oss_sndstat.c
@@ -111,7 +111,6 @@ init_status (void)
 #if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
   {
 #if defined(__FreeBSD__)
-    extern char version[];
 #endif
 
     put_status ("Kernel: ");
