
$FreeBSD$

--- src/getopt.h.orig	Sun Jul 21 13:54:13 2002
+++ src/getopt.h	Sun Jul 21 13:54:27 2002
@@ -103,7 +103,7 @@
    errors, only prototype getopt for the GNU C library.  */
 extern int getopt (int argc, char *const *argv, const char *shortopts);
 #else /* not __GNU_LIBRARY__ */
-extern int getopt ();
+/* extern int getopt (); */
 #endif /* __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,
 		        const struct option *longopts, int *longind);
