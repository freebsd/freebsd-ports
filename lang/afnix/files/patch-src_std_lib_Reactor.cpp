
$FreeBSD$

--- src/std/lib/Reactor.cpp.orig	Sun Aug 22 21:09:53 2004
+++ src/std/lib/Reactor.cpp	Sun Aug 22 21:10:10 2004
@@ -60,7 +60,7 @@
     d_size   = c_prime (0);
     d_thrs   = (d_size * 7) / 10;
     d_count  = 0;
-    p_table  = new (s_qnode*)[d_size];
+    p_table  = new s_qnode*[d_size];
     for (long i = 0; i < d_size; i++) p_table[i] = nilp;
     p_vector = new Strvec (d_size);
     p_vector->add ("");
@@ -111,7 +111,7 @@
     // check for the size
     if (size < d_size) return;
     // initialize the table
-    s_qnode** table = new (s_qnode*)[size];
+    s_qnode** table = new s_qnode*[size];
     for (long i = 0; i < size; i++) table[i] = nilp;
     // rebuild the table
     for (long i = 0; i < d_size; i++) {
