--- sql/item_subselect.cc.orig	2013-05-21 22:09:51.000000000 +0000
+++ sql/item_subselect.cc	2013-09-26 13:13:01.105197491 +0000
@@ -1317,7 +1317,7 @@
   Item_subselect()
 {
   DBUG_ENTER("Item_exists_subselect::Item_exists_subselect");
-  bool val_bool();
+//  bool val_bool();
   init(select_lex, new select_exists_subselect(this));
   max_columns= UINT_MAX;
   null_value= FALSE; //can't be NULL
