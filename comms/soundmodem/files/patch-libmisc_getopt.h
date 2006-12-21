--- libmisc/getopt.h.orig	Mon Sep 18 22:42:44 2006
+++ libmisc/getopt.h	Tue Sep 19 17:43:44 2006
@@ -101,7 +101,9 @@
    errors, only prototype getopt for the GNU C library.  */
 extern int getopt (int argc, char *const *argv, const char *shortopts);
 #else /* not __GNU_LIBRARY__ */
+#if 0
 extern int getopt ();
+#endif
 #endif /* not __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,
 		        const struct option *longopts, int *longind);
