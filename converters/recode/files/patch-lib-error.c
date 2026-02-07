--- lib/error.c.orig	Thu Aug  3 03:21:13 2000
+++ lib/error.c	Thu Apr 17 00:29:29 2003
@@ -80,7 +80,12 @@
 
 /* The calling program should define program_name and set it to the
    name of the executing program.  */
+# ifdef __FreeBSD__
+extern char *__progname;
+# define program_name __progname
+# else
 extern char *program_name;
+# endif
 
 # ifdef HAVE_STRERROR_R
 #  define __strerror_r strerror_r
