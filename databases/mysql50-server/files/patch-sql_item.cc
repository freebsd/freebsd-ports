--- sql/item.cc.orig	2007-09-20 16:57:18.000000000 +0400
+++ sql/item.cc	2007-09-20 17:00:20.000000000 +0400
@@ -1716,6 +1716,8 @@
   unsigned_flag=test(field_par->flags & UNSIGNED_FLAG);
   collation.set(field_par->charset(), field_par->derivation());
   fixed= 1;
+  if (field->table->s->tmp_table == SYSTEM_TMP_TABLE)
+    any_privileges= 0;
 }
 
 
