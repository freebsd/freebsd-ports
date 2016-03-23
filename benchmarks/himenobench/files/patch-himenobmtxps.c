--- himenobmtxps.c.orig	2002-02-21 00:27:48 UTC
+++ himenobmtxps.c
@@ -37,6 +37,7 @@
 ********************************************************************/
 
 #include <stdio.h>
+#include <sys/time.h>
 
 #ifdef SSMALL
 #define MIMAX            33
@@ -245,7 +246,6 @@ mflops(int nn,double cpu,double flop)
 double
 second()
 {
-#include <sys/time.h>
 
   struct timeval tm;
   double t ;
