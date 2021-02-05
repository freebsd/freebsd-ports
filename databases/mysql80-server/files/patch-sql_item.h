--- sql/item.h.orig	2020-12-11 07:42:20 UTC
+++ sql/item.h
@@ -3380,13 +3380,13 @@ class Item_sp_variable : public Item {
   Name_string m_name;
 
  public:
-#ifndef DBUG_OFF
+//#ifndef DBUG_OFF
   /*
     Routine to which this Item_splocal belongs. Used for checking if correct
     runtime context is used for variable handling.
   */
   sp_head *m_sp{nullptr};
-#endif
+//#endif
 
  public:
   Item_sp_variable(const Name_string sp_var_name);
