--- himenobmtxps.c~	Thu Feb 21 09:27:59 2002
+++ himenobmtxps.c	Mon Aug 16 16:13:42 2004
@@ -37,6 +37,7 @@
 ********************************************************************/
 
 #include <stdio.h>
+#include <sys/time.h>
 
 #ifdef SSMALL
 #define MIMAX            33
@@ -245,7 +246,6 @@
 double
 second()
 {
-#include <sys/time.h>
 
   struct timeval tm;
   double t ;
