--- c-posix-signals.c.orig	2015-04-30 10:20:43 UTC
+++ c-posix-signals.c
@@ -468,9 +468,9 @@ int guess_nsigs () {
  */
 
 #if defined(__APPLE__)
-# define BADSIG (0)
+# define FLOR_BADSIG (0)
 #else
-# define BADSIG (-1)
+# define FLOR_BADSIG (-1)
 #endif
 
    sigset_t set;
@@ -484,7 +484,7 @@ int guess_nsigs () {
       result = sigismember (&set, sig);
       if (result == 1) {
          last_good = sig;
-      } else if ((result == BADSIG) && (first_bad == -1)) {
+      } else if ((result == FLOR_BADSIG) && (first_bad == -1)) {
          if (sig == 0) {
             fprintf (stderr, "WARNING: C library problem? "
              "sigfillset does not include zero\n");
