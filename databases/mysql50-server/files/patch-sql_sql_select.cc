--- sql/sql_select.cc.orig	2007-09-20 16:53:57.000000000 +0400
+++ sql/sql_select.cc	2007-09-20 17:14:21.000000000 +0400
@@ -9183,7 +9183,7 @@
   bool  using_unique_constraint= 0;
   bool  use_packed_rows= 0;
   bool  not_all_columns= !(select_options & TMP_TABLE_ALL_COLUMNS);
-  char	*tmpname, *tmppath, path[FN_REFLEN], table_name[NAME_LEN+1];
+  char	*tmpname, path[FN_REFLEN];
   byte	*pos,*group_buff;
   uchar *null_flags;
   Field **reg_field, **from_field, **default_field;
@@ -9206,12 +9206,12 @@
     temp_pool_slot = bitmap_set_next(&temp_pool);
 
   if (temp_pool_slot != MY_BIT_NONE) // we got a slot
-    sprintf(table_name, "%s_%lx_%i", tmp_file_prefix,
+    sprintf(path, "%s_%lx_%i", tmp_file_prefix,
             current_pid, temp_pool_slot);
   else
   {
     /* if we run out of slots or we are not using tempool */
-    sprintf(table_name, "%s%lx_%lx_%x", tmp_file_prefix,current_pid,
+    sprintf(path, "%s%lx_%lx_%x", tmp_file_prefix,current_pid,
             thd->thread_id, thd->tmp_table++);
   }
 
@@ -9219,7 +9219,7 @@
     No need to change table name to lower case as we are only creating
     MyISAM or HEAP tables here
   */
-  fn_format(path, table_name, mysql_tmpdir, "",
+  fn_format(path, path, mysql_tmpdir, "",
             MY_REPLACE_EXT|MY_UNPACK_FILENAME);
 
   if (group)
@@ -9265,8 +9265,7 @@
                         sizeof(*key_part_info)*(param->group_parts+1),
                         &param->start_recinfo,
                         sizeof(*param->recinfo)*(field_count*2+4),
-                        &tmppath, (uint) strlen(path)+1,
-                        &tmpname, (uint) strlen(table_name)+1,
+                        &tmpname, (uint) strlen(path)+1,
                         &group_buff, group && ! using_unique_constraint ?
                         param->group_length : 0,
                         NullS))
@@ -9284,8 +9283,7 @@
     DBUG_RETURN(NULL);				/* purecov: inspected */
   }
   param->items_to_copy= copy_func;
-  strmov(tmppath, path);
-  strmov(tmpname, table_name);
+  strmov(tmpname, path);
   /* make table according to fields */
 
   bzero((char*) table,sizeof(*table));
@@ -9311,8 +9309,7 @@
 
   table->s= &table->share_not_to_be_used;
   table->s->blob_field= blob_field;
-  table->s->table_name= tmpname;
-  table->s->path= tmppath;
+  table->s->table_name= table->s->path= tmpname;
   table->s->db= "";
   table->s->blob_ptr_size= mi_portable_sizeof_char_ptr;
   table->s->tmp_table= NON_TRANSACTIONAL_TMP_TABLE;
@@ -9948,7 +9945,7 @@
 static bool open_tmp_table(TABLE *table)
 {
   int error;
-  if ((error=table->file->ha_open(table->s->table_name,O_RDWR,
+  if ((error=table->file->ha_open(table->s->path,O_RDWR,
                                   HA_OPEN_TMP_TABLE)))
   {
     table->file->print_error(error,MYF(0)); /* purecov: inspected */
@@ -10051,7 +10048,7 @@
       OPTION_BIG_TABLES)
     create_info.data_file_length= ~(ulonglong) 0;
 
-  if ((error=mi_create(table->s->table_name,table->s->keys,&keydef,
+  if ((error=mi_create(table->s->path,table->s->keys,&keydef,
 		       (uint) (param->recinfo-param->start_recinfo),
 		       param->start_recinfo,
 		       table->s->uniques, &uniquedef,
@@ -10095,7 +10092,7 @@
     */
     if (!(test_flags & TEST_KEEP_TMP_TABLES) ||
         entry->s->db_type == DB_TYPE_HEAP)
-      entry->file->delete_table(entry->s->table_name);
+      entry->file->delete_table(entry->s->path);
     delete entry->file;
   }
 
@@ -10186,7 +10183,7 @@
   /* remove heap table and change to use myisam table */
   (void) table->file->ha_rnd_end();
   (void) table->file->close();
-  (void) table->file->delete_table(table->s->table_name);
+  (void) table->file->delete_table(table->s->path);
   delete table->file;
   table->file=0;
   *table= new_table;
@@ -10203,7 +10200,7 @@
   (void) table->file->ha_rnd_end();
   (void) new_table.file->close();
  err1:
-  new_table.file->delete_table(new_table.s->table_name);
+  new_table.file->delete_table(new_table.s->path);
   delete new_table.file;
  err2:
   thd_proc_info(thd, save_proc_info);
