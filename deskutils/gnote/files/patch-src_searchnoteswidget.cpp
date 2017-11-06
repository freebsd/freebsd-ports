--- src/searchnoteswidget.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/searchnoteswidget.cpp
@@ -1520,7 +1520,7 @@ void SearchNotesWidget::parse_sorting_se
 void SearchNotesWidget::on_rename_notebook()
 {
   Glib::RefPtr<Gtk::TreeSelection> selection = m_notebooksTree->get_selection();
-  if(selection == 0) {
+  if(!selection) {
     return;
   }
   std::vector<Gtk::TreeModel::Path> selected_row = selection->get_selected_rows();
