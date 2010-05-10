--- src/noterenamedialog.cpp.orig	2010-03-14 00:32:43.000000000 -0500
+++ src/noterenamedialog.cpp	2010-03-14 00:33:46.000000000 -0500
@@ -63,6 +63,8 @@ private:
   Gtk::TreeModelColumn<Note::Ptr> m_column_note;
 };
 
+ModelColumnRecord model_column_record;
+
 ModelColumnRecord::ModelColumnRecord()
   : Gtk::TreeModelColumnRecord()
   , m_column_selected()
@@ -152,7 +154,7 @@ NoteRenameDialog::NoteRenameDialog(const
                 *renamed_note->get_window(),
                 false,
                 false)
-  , m_notes_model(Gtk::ListStore::create(ModelColumnRecord()))
+  , m_notes_model(Gtk::ListStore::create(model_column_record))
   , m_dont_rename_button(_("_Don't Rename Links"), true)
   , m_rename_button(_("_Rename Links"), true)
   , m_select_all_button(_("Select All"))
