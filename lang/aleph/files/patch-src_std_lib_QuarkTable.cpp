
$FreeBSD$

--- src/std/lib/QuarkTable.cpp.orig	Sun Aug 22 21:08:41 2004
+++ src/std/lib/QuarkTable.cpp	Sun Aug 22 21:09:12 2004
@@ -86,7 +86,7 @@
     d_size   = c_prime (0);
     d_thrs   = (d_size * 7) / 10;
     d_count  = 0;
-    p_table  = new (s_quanode*)[d_size];
+    p_table  = new s_quanode*[d_size];
     for (long i = 0; i < d_size; i++) p_table[i] = nilp;
   }
   
@@ -97,7 +97,7 @@
     d_size   = c_prime (size);
     d_thrs   = (size * 7) / 10;
     d_count  = 0;
-    p_table  = new (s_quanode*)[d_size];    
+    p_table  = new s_quanode*[d_size];    
     for (long i = 0; i < d_size; i++) p_table[i] = nilp;
   }
   
@@ -251,7 +251,7 @@
     if (size < d_size) return;
 
     // initialize the new table
-    s_quanode** table = new (s_quanode*)[size];
+    s_quanode** table = new s_quanode*[size];
     for (long i = 0; i < size; i++) table[i] = nilp;
 
     // rebuild the table
