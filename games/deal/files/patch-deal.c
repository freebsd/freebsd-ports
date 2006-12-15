--- deal.c.orig	Fri Sep 27 00:31:22 1996
+++ deal.c	Fri Dec 15 01:00:03 2006
@@ -35,6 +35,7 @@
  * rounds to zero.
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
 #include <signal.h>
 
@@ -49,6 +50,7 @@
 static int verbose = FALSE;
 
 static double log_a_choose_b(int a, int b);
+static double hyper_prob(int, int, int, int);
 
 static void hypercatch(int sig)
 {
@@ -80,7 +82,6 @@
 {
     extern char	*optarg;	/* set by getopt */
     extern int	optind;		/* set by getopt */
-    static double hyper_prob();
 
     int status, special, total, columns, i, j;
     int base = BASE_DEFAULT;
