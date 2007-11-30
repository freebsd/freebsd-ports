--- deal.c.orig	1996-09-27 00:31:22.000000000 +0200
+++ deal.c	2007-11-30 00:00:29.000000000 +0100
@@ -35,8 +35,10 @@
  * rounds to zero.
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
 #include <signal.h>
+#include <unistd.h>
 
 #define BASE_DEFAULT	7	/* # cards in initial deal */
 #define TURNS_DEFAULT	20	/* show this many turns if total is greater */
@@ -49,6 +51,7 @@
 static int verbose = FALSE;
 
 static double log_a_choose_b(int a, int b);
+static double hyper_prob(int, int, int, int);
 
 static void hypercatch(int sig)
 {
@@ -74,13 +77,12 @@
     exit(0);
 }
 
-main(argc, argv)
+int main(argc, argv)
 int argc;
 char **argv;
 {
     extern char	*optarg;	/* set by getopt */
     extern int	optind;		/* set by getopt */
-    static double hyper_prob();
 
     int status, special, total, columns, i, j;
     int base = BASE_DEFAULT;
@@ -97,11 +99,11 @@
 	switch (status)
 	{
 	case 'b':
-	    base = atoi(optarg);
+	    base = (int)strtol(optarg, (char **)NULL, 10);
 	    break;
 
 	case 'c':
-	    columns = atoi(optarg);
+	    columns = (int)strtol(optarg, (char **)NULL, 10);
 	    break;
 
 	case 'G':
@@ -142,7 +144,7 @@
     }	
 
     if (gammatest) {
-	double p = lgamma(atoi(argv[optind]));
+	double p = lgamma(strtod(argv[optind], (char **)NULL));
 
 	(void) printf("lgamma(%d) = %f\n", atoi(argv[optind]), p);
 	exit(0);
@@ -212,7 +214,7 @@
 	(void) printf("\n");
 	(void) printf("-----+");
 	for (j = 0; j < columns; j++)
-	    (void) printf(wide ? "----" : "---", j);
+	    (void) printf(wide ? "----" : "---");
 	(void) printf("\n");
     }
 
@@ -239,6 +241,8 @@
 
 	(void) printf("\n");
     }
+
+    return (0);
 }
 
 /* 
@@ -276,7 +280,8 @@
     sa = a;
     sb = b;
 
-    signal(SIGFPE, choosecatch);
+    if(signal(SIGFPE, choosecatch) == SIG_ERR)
+      exit(EXIT_FAILURE);
 
     if (b >= a)
 	p = 0;
@@ -287,7 +292,8 @@
     if (verbose)
 	(void) fprintf(stderr, "log_a_choose_b(%d, %d) = %f\n", a, b, p);
 
-    signal(SIGFPE, hypercatch);
+    if(signal(SIGFPE, hypercatch) == SIG_ERR)
+       exit(EXIT_FAILURE);
 
     return(p);
 }
