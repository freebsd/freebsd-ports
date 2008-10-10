--- sql/sql_parse.cc	2007-06-12 12:47:36 +0000
+++ sql/sql_parse.cc	2008-02-29 09:55:00 +0000
@@ -65,7 +65,8 @@
 			       const char *table_name);
              
 static TABLE_LIST* get_table_by_alias(TABLE_LIST* tl, const char* db,
-  const char* alias);      
+  const char* alias);
+static bool test_if_data_home_dir(const char *dir);
 
 const char *any_db="*any*";	// Special symbol for check_access
 
@@ -2531,6 +2532,20 @@
                    "INDEX DIRECTORY option ignored");
     create_info.data_file_name= create_info.index_file_name= NULL;
 #else
+
+    if (test_if_data_home_dir(lex->create_info.data_file_name))
+    {
+      my_error(ER_WRONG_ARGUMENTS,MYF(0),"DATA DIRECORY");
+      res= -1;
+      break;
+    }
+    if (test_if_data_home_dir(lex->create_info.index_file_name))
+    {
+      my_error(ER_WRONG_ARGUMENTS,MYF(0),"INDEX DIRECORY");
+      res= -1;
+      break;
+    }
+
     /* Fix names if symlinked tables */
     if (append_file_to_dir(thd, &create_info.data_file_name,
 			   create_table->real_name) ||
@@ -5920,3 +5935,47 @@
     return negated;
   return new Item_func_not(expr);
 }
+
+
+/*
+  Check if path does not contain mysql data home directory
+
+  SYNOPSIS
+    test_if_data_home_dir()
+    dir                     directory
+    conv_home_dir           converted data home directory
+    home_dir_len            converted data home directory length
+
+  RETURN VALUES
+    0	ok
+    1	error  
+*/
+
+static bool test_if_data_home_dir(const char *dir)
+{
+  char path[FN_REFLEN], conv_path[FN_REFLEN];
+  uint dir_len, home_dir_len= strlen(mysql_unpacked_real_data_home);
+  DBUG_ENTER("test_if_data_home_dir");
+
+  if (!dir)
+    DBUG_RETURN(0);
+
+  (void) fn_format(path, dir, "", "",
+                   (MY_RETURN_REAL_PATH|MY_RESOLVE_SYMLINKS));
+  dir_len= unpack_dirname(conv_path, dir);
+
+  if (home_dir_len <= dir_len)
+  {
+    if (lower_case_file_system)
+    {
+      if (!my_strnncoll(default_charset_info, (const uchar*) conv_path,
+                        home_dir_len,
+                        (const uchar*) mysql_unpacked_real_data_home,
+                        home_dir_len))
+        DBUG_RETURN(1);
+    }
+    else if (!memcmp(conv_path, mysql_unpacked_real_data_home, home_dir_len))
+      DBUG_RETURN(1);
+  }
+  DBUG_RETURN(0);
+}

