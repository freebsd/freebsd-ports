--- util/testgaussgen.c.orig	2011-08-05 12:28:30.000000000 -0400
+++ util/testgaussgen.c	2011-08-05 12:31:35.000000000 -0400
@@ -72,7 +72,7 @@
  * with nrand = 16 and randommax = 0x1000
  */
 
-extern __inline__ float randn(void)
+__inline__ float randn(void)
 {
         int sum = 0, i;
 
