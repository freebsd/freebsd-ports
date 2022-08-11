--- pb.h.orig	2022-07-03 17:53:31 UTC
+++ pb.h
@@ -11,7 +11,7 @@
  *****************************************************************/
 
 /* Enable support for dynamically allocated fields */
-/* #define PB_ENABLE_MALLOC 1 */
+#define PB_ENABLE_MALLOC 1
 
 /* Define this if your CPU / compiler combination does not support
  * unaligned memory access to packed structures. Note that packed
