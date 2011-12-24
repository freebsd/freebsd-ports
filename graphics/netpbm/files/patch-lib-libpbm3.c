--- lib/libpbm3.c	2008-03-28 19:58:06.000000000 +0100
+++ lib/libpbm3.c	2011-12-18 11:55:05.000000000 +0100
@@ -117,10 +117,10 @@
             ) ];
     */
 
-    typedef int v8qi __attribute__ ((mode(V8QI)));
-    typedef int di __attribute__ ((mode(DI)));
+    typedef char v8qi __attribute__ ((vector_size(8)));
+    typedef int di __attribute__ ((vector_size(8)));
 
-    di const zero64 = 0;        /* to clear with PXOR */
+    di const zero64 = (di){0};        /* to clear with PXOR */
 
     unsigned int col;
 
