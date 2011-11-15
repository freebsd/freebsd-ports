--- ./xtrader/src/gui/ReportView.cpp.orig	2004-11-14 11:21:30.000000000 +0100
+++ ./xtrader/src/gui/ReportView.cpp	2011-11-15 13:46:19.000000000 +0100
@@ -21,13 +21,13 @@
 #include "Resource.h"
 #include <MHDate.h>
 #include <MHVector.h>
-#include <FL/Fl.h>
-#include <FL/fl_ask.h>
-#include <FL/fl_draw.h>
-#include <FL/Fl_Button.h>
-#include <FL/Fl_File_Chooser.h>
+#include <FL/Fl.H>
+#include <FL/fl_ask.H>
+#include <FL/fl_draw.H>
+#include <FL/Fl_Button.H>
+#include <FL/Fl_File_Chooser.H>
 #include <fl/Fl_Layout.h>
-#include <FL/Fl_Hold_Browser.h>
+#include <FL/Fl_Hold_Browser.H>
 #include <fl/Fl_Table.h>
 #include <fl/Fl_Table_Data.h>
 
@@ -139,7 +139,15 @@
 void ReportView::cbBrowser2 () {
 }
 
-
+/**
+ * Callback for file chooser
+ */
+void rep_fc_callback(Fl_File_Chooser *fc, void *data)
+{
+	Report *r = static_cast<Report *>(data);
+	const char *file = fc->value();
+	if (file && *file) r->Save (file);
+}
 
 /**
 *  Callback for buttons
@@ -173,8 +181,9 @@
             Report* r = ((ReportData*)aTable->data())->report();
 
             if (r) {
-                char* file = fl_file_chooser (STRING(DLG_SELECT_WRITE_FILE), "*.*", "");
-                if (file && *file) r->Save (file);
+                Fl_File_Chooser *fc = new Fl_File_Chooser (STRING(DLG_SELECT_WRITE_FILE), "*.*", Fl_File_Chooser::SINGLE, "");
+                fc->callback(rep_fc_callback, r);
+                delete fc;
             }
         }
         else if (strcmp (button->label(), STRING(SELECT2)) == 0) {
