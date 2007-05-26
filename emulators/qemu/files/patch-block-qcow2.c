Index: qemu/block-qcow2.c
@@ -1886,6 +1886,8 @@
     int64_t table_offset;
     uint64_t data64;
     uint32_t data32;
+    int old_table_size;
+    int64_t old_table_offset;
 
     if (min_size <= s->refcount_table_size)
         return 0;
@@ -1931,10 +1933,14 @@
                     &data32, sizeof(data32)) != sizeof(data32))
         goto fail;
     qemu_free(s->refcount_table);
+    old_table_offset = s->refcount_table_offset;
+    old_table_size = s->refcount_table_size;
     s->refcount_table = new_table;
     s->refcount_table_size = new_table_size;
+    s->refcount_table_offset = table_offset;
 
     update_refcount(bs, table_offset, new_table_size2, 1);
+    free_clusters(bs, old_table_offset, old_table_size * sizeof(uint64_t));
     return 0;
  fail:
     free_clusters(bs, table_offset, new_table_size2);
