--- GG/src/dialogs/FileDlg.cpp.orig	2023-03-21 15:16:58 UTC
+++ GG/src/dialogs/FileDlg.cpp
@@ -9,7 +9,7 @@
 
 #include <boost/cast.hpp>
 #include <boost/algorithm/string/predicate.hpp>
-#include <boost/filesystem/operations.hpp>
+#include <boost/filesystem.hpp>
 #include <boost/format.hpp>
 // boost::spirit::classic pulls in windows.h which in turn defines macro
 // versions of min and max.  Defining NOMINMAX disables the creation of those
@@ -215,7 +215,7 @@ void FileDlg::CompleteConstruction()
 
     if (!m_init_filename.empty()) {
         fs::path filename_path = fs::system_complete(fs::path(m_init_filename));
-        m_files_edit->SetText(filename_path.leaf().string());
+        m_files_edit->SetText(filename_path.filename().string());
     }
 }
 
@@ -548,7 +548,7 @@ void FileDlg::UpdateList()
     if (!m_in_win32_drive_selection) {
         // parent directory selector
         if ((s_working_dir.string() != s_working_dir.root_path().string() &&
-             !s_working_dir.branch_path().string().empty()) ||
+             !s_working_dir.parent_path().string().empty()) ||
             Win32Paths())
         {
             auto row = Wnd::Create<ListBox::Row>();
@@ -694,10 +694,10 @@ void FileDlg::OpenDirectory()
     } else if (directory == "..") {
         // move to parent directory of current directory
         if (s_working_dir.string() != s_working_dir.root_path().string() &&
-            !s_working_dir.branch_path().string().empty())
+            !s_working_dir.parent_path().string().empty())
         {
             // move to new directory
-            SetWorkingDirectory(s_working_dir.branch_path());
+            SetWorkingDirectory(s_working_dir.parent_path());
 
         } else {
             // switch to drive selection mode
