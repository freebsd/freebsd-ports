--- glom/mode_design/layout/layout_item_dialogs/box_formatting.cc.orig	2014-03-06 22:26:17.000000000 +0100
+++ glom/mode_design/layout/layout_item_dialogs/box_formatting.cc	2014-03-06 22:26:37.000000000 +0100
@@ -187,8 +187,8 @@
     {
       //Display the value in the choices list as it would be displayed in the format:
       const Glib::ustring value_text = Conversions::get_text_for_gda_value(m_field->get_glom_type(), *iter, format.m_numeric_format);
-      Gtk::TreeModel::iterator iter = m_adddel_choices_custom->add_item(value_text);
-      m_adddel_choices_custom->set_value(iter, m_col_index_custom_choices, value_text);
+      Gtk::TreeModel::iterator tree_iter = m_adddel_choices_custom->add_item(value_text);
+      m_adddel_choices_custom->set_value(tree_iter, m_col_index_custom_choices, value_text);
     }
 
     m_radiobutton_choices_custom->set_active(format.get_has_custom_choices());
