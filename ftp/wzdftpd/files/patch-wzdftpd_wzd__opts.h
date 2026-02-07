--- wzdftpd/wzd_opts.h.orig	2023-02-11 11:32:00 UTC
+++ wzdftpd/wzd_opts.h
@@ -24,11 +24,7 @@ struct option
 #define optional_argument       2
 
 #if __STDC__
-#if defined(__GNU_LIBRARY__)
 extern int getopt (int argc, char *const *argv, const char *shortopts);
-#else /* not __GNU_LIBRARY__ */
-extern int getopt ();
-#endif /* not __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char
 *shortopts,                        const struct option *longopts, int
 *longind); extern int getopt_long_only (int argc, char *const *argv,
