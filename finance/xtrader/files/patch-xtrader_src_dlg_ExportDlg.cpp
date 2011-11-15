--- ./xtrader/src/dlg/ExportDlg.cpp.orig	2004-11-14 11:21:29.000000000 +0100
+++ ./xtrader/src/dlg/ExportDlg.cpp	2011-11-15 13:46:19.000000000 +0100
@@ -14,9 +14,9 @@
 #include <help/Export.h>
 #include <MHDate.h>
 #include <MHDebug.h>
-#include <FL/fl_draw.h>
-#include <FL/fl_ask.h>
-#include <FL/Fl_File_Chooser.h>
+#include <FL/fl_draw.H>
+#include <FL/fl_ask.H>
+#include <FL/Fl_File_Chooser.H>
 
 
 
@@ -134,13 +134,23 @@
 }
 
 
+/**
+ * Callback for file chooser
+ */
+void exp_fc_callback(Fl_File_Chooser *fc, void *data)
+{
+	ExportDlg *e = static_cast<ExportDlg *>(data);
+	const char *file = fc->value();
+	if (file && *file) e->aFile->value(file);
+}
 
 /**
 *  Get filename
 */
 void ExportDlg::cb3 () {
-    char* file = fl_file_chooser (STRING(DLG_SELECT_WRITE_FILE), "*.*", "");
-    if (file && *file) aFile->value (file);
+    Fl_File_Chooser *fc = new Fl_File_Chooser(STRING(DLG_SELECT_WRITE_FILE), "*.*", Fl_File_Chooser::SINGLE, "");
+    fc->callback(exp_fc_callback, this);
+    delete fc;
 }
 
 
