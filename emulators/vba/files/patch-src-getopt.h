--- src/getopt.h.orig	Sun Oct  9 23:31:12 2005
+++ src/getopt.h	Sun Oct  9 23:31:25 2005
@@ -112,7 +112,7 @@
 extern int getopt (int argc, char *const *argv, const char *shortopts);
 #else /* not __GNU_LIBRARY__ */
 # if !defined (HAVE_DECL_GETOPT)
-extern int getopt ();
+//extern int getopt ();
 # endif
 #endif /* __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,
