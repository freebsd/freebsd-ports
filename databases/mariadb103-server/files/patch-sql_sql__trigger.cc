--- sql/sql_trigger.cc.orig	2018-02-26 04:27:17.000000000 +0100
+++ sql/sql_trigger.cc	2018-02-27 20:54:20.250859000 +0100
@@ -178,37 +178,37 @@ static File_option triggers_file_paramet
 {
   {
     { STRING_WITH_LEN("triggers") },
-    my_offsetof(class Table_triggers_list, definitions_list),
+    static_cast<int>(my_offsetof(class Table_triggers_list, definitions_list)),
     FILE_OPTIONS_STRLIST
   },
   {
     { STRING_WITH_LEN("sql_modes") },
-    my_offsetof(class Table_triggers_list, definition_modes_list),
+    static_cast<int>(my_offsetof(class Table_triggers_list, definition_modes_list)),
     FILE_OPTIONS_ULLLIST
   },
   {
     { STRING_WITH_LEN("definers") },
-    my_offsetof(class Table_triggers_list, definers_list),
+    static_cast<int>(my_offsetof(class Table_triggers_list, definers_list)),
     FILE_OPTIONS_STRLIST
   },
   {
     { STRING_WITH_LEN("client_cs_names") },
-    my_offsetof(class Table_triggers_list, client_cs_names),
+    static_cast<int>(my_offsetof(class Table_triggers_list, client_cs_names)),
     FILE_OPTIONS_STRLIST
   },
   {
     { STRING_WITH_LEN("connection_cl_names") },
-    my_offsetof(class Table_triggers_list, connection_cl_names),
+    static_cast<int>(my_offsetof(class Table_triggers_list, connection_cl_names)),
     FILE_OPTIONS_STRLIST
   },
   {
     { STRING_WITH_LEN("db_cl_names") },
-    my_offsetof(class Table_triggers_list, db_cl_names),
+    static_cast<int>(my_offsetof(class Table_triggers_list, db_cl_names)),
     FILE_OPTIONS_STRLIST
   },
   {
     { STRING_WITH_LEN("created") },
-    my_offsetof(class Table_triggers_list, create_times),
+    static_cast<int>(my_offsetof(class Table_triggers_list, create_times)),
     FILE_OPTIONS_ULLLIST
   },
   { { 0, 0 }, 0, FILE_OPTIONS_STRING }
@@ -217,7 +217,7 @@ static File_option triggers_file_paramet
 File_option sql_modes_parameters=
 {
   { STRING_WITH_LEN("sql_modes") },
-  my_offsetof(class Table_triggers_list, definition_modes_list),
+  static_cast<int>(my_offsetof(class Table_triggers_list, definition_modes_list)),
   FILE_OPTIONS_ULLLIST
 };
 
