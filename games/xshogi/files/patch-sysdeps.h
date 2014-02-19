--- sysdeps.h.orig	2014-02-19 13:11:16.000000000 +0100
+++ sysdeps.h	2014-02-19 13:11:20.000000000 +0100
@@ -74,16 +74,6 @@
 #include <sys/time.h>
 #include <fcntl.h>
 
-/*
- * Stuff that isn't reliably included (on Linux, anyway).
- */
-
-extern FILE *fdopen(int fd, const char *modes);
-extern int   fileno(FILE *stream);
-extern int   kill(pid_t pid, int sig);
-extern int   strcasecmp(const char *s1, const char *s2);
-extern int   gethostname(char *name, size_t len);
-
 
 /*
  * Check for POSIX-compatible wait().
