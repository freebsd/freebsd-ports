--- jam.c.orig	2014-08-07 15:39:04.000000000 +0200
+++ jam.c	2014-08-07 15:39:24.000000000 +0200
@@ -167,7 +167,7 @@
 # endif
 
 int
-main( int argc, char **argv, char **arg_environ )
+main( int argc, char **argv )
 {
 	int		n, num_targets;
 	const char	*s;
