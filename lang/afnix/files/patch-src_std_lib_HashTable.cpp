
$FreeBSD$

--- src/std/lib/HashTable.cpp.orig	Sun Aug 22 21:07:04 2004
+++ src/std/lib/HashTable.cpp	Sun Aug 22 21:07:46 2004
@@ -90,7 +90,7 @@
     d_size   = c_prime (0);
     d_thrs   = (d_size * 7) / 10;
     d_count  = 0;
-    p_table  = new (s_bucket*)[d_size];
+    p_table  = new s_bucket*[d_size];
     
     // initialize the table with null pointers
     for (long i = 0; i < d_size; i++)
@@ -104,7 +104,7 @@
     d_size   = c_prime (size);
     d_thrs   = (size * 7) / 10;
     d_count  = 0;
-    p_table  = new (s_bucket*)[d_size];
+    p_table  = new s_bucket*[d_size];
     
     // initialize the table with null pointers
     for (long i = 0; i < d_size; i++)
@@ -248,7 +248,7 @@
     if (size < d_size) return;
 
     // initialize the new table
-    s_bucket** table = new (s_bucket*)[size];
+    s_bucket** table = new s_bucket*[size];
     for (long i = 0; i < size; i++) table[i] = nilp;
 
     // rebuild the table
