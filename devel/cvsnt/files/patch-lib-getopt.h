--- lib/getopt.h.orig	Sun Jan 25 20:07:35 2004
+++ lib/getopt.h	Sun Jan 25 20:08:37 2004
@@ -97,7 +97,7 @@
    exactly why), and there is no particular need to prototype it.
    We really shouldn't be trampling on the system's namespace at all by
    declaring getopt() but that is a bigger issue.  */
-extern int getopt ();
+extern int getopt (int argc, char *const argv[], const char *shortopts);
 
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,
 		        const struct option *longopts, int *longind);
