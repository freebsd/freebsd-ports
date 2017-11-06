--- sql/sql_trigger.cc.orig	2012-08-02 00:01:13.000000000 +0200
+++ sql/sql_trigger.cc	2012-09-11 17:01:13.000000000 +0200
@@ -192,32 +192,32 @@ static File_option triggers_file_parameters[]=
 {
   {
     { C_STRING_WITH_LEN("triggers") },
-    my_offsetof(class Table_triggers_list, definitions_list),
+    static_cast<int>(my_offsetof(class Table_triggers_list, definitions_list)),
     FILE_OPTIONS_STRLIST
   },
   {
     { C_STRING_WITH_LEN("sql_modes") },
-    my_offsetof(class Table_triggers_list, definition_modes_list),
+    static_cast<int>(my_offsetof(class Table_triggers_list, definition_modes_list)),
     FILE_OPTIONS_ULLLIST
   },
   {
     { C_STRING_WITH_LEN("definers") },
-    my_offsetof(class Table_triggers_list, definers_list),
+    static_cast<int>(my_offsetof(class Table_triggers_list, definers_list)),
     FILE_OPTIONS_STRLIST
   },
   {
     { C_STRING_WITH_LEN("client_cs_names") },
-    my_offsetof(class Table_triggers_list, client_cs_names),
+    static_cast<int>(my_offsetof(class Table_triggers_list, client_cs_names)),
     FILE_OPTIONS_STRLIST
   },
   {
     { C_STRING_WITH_LEN("connection_cl_names") },
-    my_offsetof(class Table_triggers_list, connection_cl_names),
+    static_cast<int>(my_offsetof(class Table_triggers_list, connection_cl_names)),
     FILE_OPTIONS_STRLIST
   },
   {
     { C_STRING_WITH_LEN("db_cl_names") },
-    my_offsetof(class Table_triggers_list, db_cl_names),
+    static_cast<int>(my_offsetof(class Table_triggers_list, db_cl_names)),
     FILE_OPTIONS_STRLIST
   },
   { { 0, 0 }, 0, FILE_OPTIONS_STRING }
@@ -226,7 +226,7 @@ static File_option triggers_file_parameters[]=
 File_option sql_modes_parameters=
 {
   { C_STRING_WITH_LEN("sql_modes") },
-  my_offsetof(class Table_triggers_list, definition_modes_list),
+  static_cast<int>(my_offsetof(class Table_triggers_list, definition_modes_list)),
   FILE_OPTIONS_ULLLIST
 };
 
