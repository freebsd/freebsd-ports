--- util/channel.c.orig	2011-08-05 12:18:02.000000000 -0400
+++ util/channel.c	2011-08-05 12:18:21.000000000 -0400
@@ -217,7 +217,7 @@
  * with nrand = 16 and randommax = 0x1000
  */
 
-extern __inline__ float randn(void)
+__inline__ float randn(void)
 {
         int sum = 0, i;
 
