
$FreeBSD$

--- nmixer/getopt.h.orig	Thu Mar  6 00:37:11 2003
+++ nmixer/getopt.h	Thu Mar  6 00:37:21 2003
@@ -103,7 +103,7 @@
    errors, only prototype getopt for the GNU C library.  */
 extern int getopt (int argc, char *const *argv, const char *shortopts);
 #else /* not __GNU_LIBRARY__ */
-extern int getopt ();
+/* extern int getopt (); */
 #endif /* __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,
 		        const struct option *longopts, int *longind);
