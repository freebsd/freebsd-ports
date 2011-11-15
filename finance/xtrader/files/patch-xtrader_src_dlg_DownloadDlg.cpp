--- ./xtrader/src/dlg/DownloadDlg.cpp.orig	2004-11-14 11:21:30.000000000 +0100
+++ ./xtrader/src/dlg/DownloadDlg.cpp	2011-11-15 13:46:19.000000000 +0100
@@ -21,8 +21,8 @@
 #include "Enums.h"
 #include "Progress.h"
 #include "Resource.h"
-#include <FL/fl_ask.h>
-#include <FL/Fl_File_Chooser.h>
+#include <FL/fl_ask.H>
+#include <FL/Fl_File_Chooser.H>
 #include <MHDate.h>
 #include <MHDebug.h>
 #include <MHFile.h>
@@ -164,13 +164,24 @@
 }
 
 
+/**
+ * Callback for file chooser
+ */
+void dlg_fc_callback(Fl_File_Chooser *fc, void *data)
+{
+	DownloadDlg *d = static_cast<DownloadDlg *>(data);
+	const char *file = fc->value();
+	if (file && *file) d->aFile->value(file);
+
+}
 
 /**
 * Browse for result file name
 */
 void DownloadDlg::cb3 () {
-    char* file = fl_file_chooser (STRING(DLG_SELECT_WRITE_FILE), "*.*", "");
-    if (file && *file) aFile->value (file);
+    Fl_File_Chooser *fc = new Fl_File_Chooser (STRING(DLG_SELECT_WRITE_FILE), "*.*", Fl_File_Chooser::SINGLE, "");
+    fc->callback(dlg_fc_callback, this);
+    delete fc;
 }
 
 
