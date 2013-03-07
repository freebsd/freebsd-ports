--- runtime/gc/int-inf.c.orig	2010-06-11 06:35:14.000000000 -0700
+++ runtime/gc/int-inf.c	2013-02-17 15:45:47.000000000 -0800
@@ -6,6 +6,10 @@
  * See the file MLton-LICENSE for details.
  */
 
+#ifndef __gmp_const
+# define __gmp_const const
+#endif
+
 /*
  * Test if a intInf is a fixnum.
  */
