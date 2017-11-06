--- deps/eleveldb/c_src/leveldb/util/perf_count.cc.orig	2017-01-08 11:38:09.374810000 +0200
+++ deps/eleveldb/c_src/leveldb/util/perf_count.cc	2017-01-21 00:09:02.610066000 +0200
@@ -360,11 +360,11 @@
             uint32_t ret_32, * ptr_32;
 
             ptr_32=(uint32_t *)&val_ptr;
-            ret_32=inc_and_fetch(ptr_32, 1);
+            ret_32=inc_and_fetch(ptr_32);
             if (0==ret_32)
             {
                 ++ptr_32;
-                inc_and_fetch(ptr_32, 1);
+                inc_and_fetch(ptr_32);
             }   // if
 #endif
             ret_val=*val_ptr;
@@ -432,11 +432,11 @@
 
             ptr_32=(uint32_t *)&val_ptr;
             old_32=*ptr_32;
-            ret_32=add_and_fetch(ptr_32, Amount);
+            ret_32=add_and_fetch(ptr_32, (uint32_t)Amount);
             if (ret_32<old_32)
             {
                 ++ptr_32;
-                add_and_fetch(ptr_32, 1);
+                add_and_fetch(ptr_32, (uint32_t)1);
             }   // if
 
             ret_val=*val_ptr;
