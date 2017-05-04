--- sql/item_subselect.cc.orig	2017-04-30 11:09:31 UTC
+++ sql/item_subselect.cc
@@ -1329,7 +1329,7 @@ Item_exists_subselect::Item_exists_subse
   Item_subselect()
 {
   DBUG_ENTER("Item_exists_subselect::Item_exists_subselect");
-  bool val_bool();
+//  bool val_bool();
   init(select_lex, new select_exists_subselect(this));
   max_columns= UINT_MAX;
   null_value= FALSE; //can't be NULL
