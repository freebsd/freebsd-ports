--- glom/mode_design/fields/box_db_table_definition.cc.orig	2014-03-06 22:10:39.000000000 +0100
+++ glom/mode_design/fields/box_db_table_definition.cc	2014-03-06 22:16:25.000000000 +0100
@@ -143,8 +143,8 @@
       const sharedptr<const Field>& field = *iter;
 
       //Name:
-      Gtk::TreeModel::iterator iter= m_AddDel.add_item(field->get_name());
-      fill_field_row(iter, field);
+      Gtk::TreeModel::iterator tree_iter= m_AddDel.add_item(field->get_name());
+      fill_field_row(tree_iter, field);
     }
 
     result = true;
