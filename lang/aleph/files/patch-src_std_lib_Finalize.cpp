
$FreeBSD$

--- src/std/lib/Finalize.cpp.orig	Sun Aug 22 21:06:42 2004
+++ src/std/lib/Finalize.cpp	Sun Aug 22 21:06:51 2004
@@ -27,7 +27,7 @@
     d_size = FIFO_SIZE;
     d_pos  = FIFO_SIZE-1;
     d_lock = false;
-    p_fifo = new (Object*)[d_size];
+    p_fifo = new Object*[d_size];
     for (long i = 0; i < d_size; i++) p_fifo[i] = nilp;
   }
 
