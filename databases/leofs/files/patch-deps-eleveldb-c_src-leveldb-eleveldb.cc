--- deps/eleveldb/c_src/eleveldb.cc.orig	2015-07-04 18:36:42.000000000 +0300
+++ deps/eleveldb/c_src/eleveldb.cc	2015-07-04 18:36:54.000000000 +0300
@@ -240,7 +240,7 @@
     {
         if (option[0] == eleveldb::ATOM_TOTAL_LEVELDB_MEM)
         {
-            size_t memory_sz;
+            unsigned long memory_sz;
             if (enif_get_ulong(env, option[1], &memory_sz))
             {
                 if (memory_sz != 0)
@@ -328,7 +328,7 @@
         }
         else if (option[0] == eleveldb::ATOM_BLOCK_CACHE_THRESHOLD)
         {
-            size_t memory_sz;
+            unsigned long memory_sz;
             if (enif_get_ulong(env, option[1], &memory_sz))
             {
                 if (memory_sz != 0)
@@ -581,7 +581,7 @@
     // 4. fail safe when no guidance given
     if (0==priv.m_Opts.m_TotalMem && 0==priv.m_Opts.m_TotalMemPercent)
     {
-        if (8*1024*1024*1024L < gCurrentTotalMemory)
+        if (8*1024*1024*1024LL < gCurrentTotalMemory)
             use_memory=(gCurrentTotalMemory * 80)/100;  // integer percent
         else
             use_memory=(gCurrentTotalMemory * 25)/100;  // integer percent
