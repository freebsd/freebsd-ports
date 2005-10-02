--- src/callchain.c.orig	Mon Feb  3 09:03:54 2003
+++ src/callchain.c	Sun Jun 26 12:37:45 2005
@@ -1154,9 +1154,10 @@
  * a bug in gcc 2.95.4 and 3.0.4; maybe fixed more recently.
  *
  * (Edward Welbourne).
+ *
+ * Fixed to use __builtin_frame_address() by Bram Moolenaar.
  */
-#define RA(a) case a: return (caddr_t) \
-__builtin_return_address(a) ? __builtin_return_address(a) : (caddr_t) 0;
+#define RA(a) case a: return (caddr_t) (__builtin_frame_address(a) ? __builtin_return_address(a) : 0);
 
 static caddr_t
 return_address (unsigned i)
