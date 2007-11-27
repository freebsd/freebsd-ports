--- include/sim.h.orig	1992-10-07 04:51:27.000000000 +0100
+++ include/sim.h	2007-11-23 23:51:50.000000000 +0100
@@ -4,7 +4,9 @@
 
 #include <sys/types.h>
 #include <strings.h>
+#include <string.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
 
 /* Things for all simulator routines */
@@ -83,14 +85,11 @@
 #define CONST
 #endif  /* __STDC__ */
 
-extern char *strncpy(), *strcpy(), *strcat(), *strncat();
-extern char *calloc(), *malloc(), *realloc();
 char *sim_calloc(), *sim_malloc(), *sim_realloc();
 void panic();
 
 /** Largest number returned by random(). (2**31)-1   From RANDOM(3) */
 #define MAX_RANDOM_NUMBER 2147483647
-extern long random();
 double random_range();
 
 #define min(a, b)  ((a) < (b) ? (a) : (b))
