--- common/getopt.c.orig	Wed Oct  3 23:28:45 2007
+++ common/getopt.c	Wed Oct  3 23:29:03 2007
@@ -21,7 +21,7 @@
 int	optopt, opterr = TRUE, optind = 1;
 char	*optarg;
 
-static	int	sp = 1;
+int	sp = 1;
 
 int getopt( int argc, char * const argv[], const char *opts )
 {
