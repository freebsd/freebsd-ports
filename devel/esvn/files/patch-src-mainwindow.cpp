--- src/mainwindow.cpp.orig	Sun Aug 15 16:11:59 2004
+++ src/mainwindow.cpp	Sun Aug 15 16:12:07 2004
@@ -14,6 +14,7 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <unistd.h>
 #include "mainwindow.h"
 
 #include <qlistview.h>
@@ -441,7 +442,7 @@
 	QListViewItem *selected_item = list_files->selectedItem();
 
 	bool was_selected = (selected_item != 0);
-	QString file_name = was_selected ? selected_item->text(0) : "";
+	QString file_name = was_selected ? selected_item->text(0) : (QString)"";
 
 	C_FilesList file_list;
 	file_list.load(selected_path_, list_files, hide_unknown_);
@@ -635,7 +636,7 @@
 
 			int res = svn_commands_->cat(workingFileDir(), rev, file2);
 			if (res == 0) {
-				QString rev_str = (rev == "") ? "last" : rev;
+				QString rev_str = (rev == "") ? (QString)"last" : rev;
 				diff_tmp_file_ = workingFileDir()+".r_" + rev_str;
 				FILE *fh_tmp = fopen(diff_tmp_file_.local8Bit(), "wb");
 				if (fh_tmp != NULL) {
