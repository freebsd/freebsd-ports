--- getopt.h.orig	Sun Jul  9 14:05:07 2006
+++ getopt.h	Sun Jul  9 14:14:23 2006
@@ -111,7 +111,7 @@
    errors, only prototype getopt for the GNU C library.  */
 extern int getopt (int argc, char *const *argv, const char *shortopts);
 #else /* not __GNU_LIBRARY__ */
-# if !defined (HAVE_DECL_GETOPT)
+# if !defined (HAVE_DECL_GETOPT) && !defined(__cplusplus)
 extern int getopt ();
 # endif
 #endif /* __GNU_LIBRARY__ */
