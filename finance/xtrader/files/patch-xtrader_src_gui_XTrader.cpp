--- ./xtrader/src/gui/XTrader.cpp.orig	2004-11-14 11:21:30.000000000 +0100
+++ ./xtrader/src/gui/XTrader.cpp	2011-11-15 13:46:19.000000000 +0100
@@ -34,11 +34,11 @@
 #include "table/SecurityData.h"
 #include "table/SetData.h"
 #include "table/SetItemData.h"
-#include <FL/Fl.h>
-#include <FL/Fl_Box.h>
-#include <FL/fl_file_chooser.h>
+#include <FL/Fl.H>
+#include <FL/Fl_Box.H>
+#include <FL/Fl_File_Chooser.H>
 #include <fl/Fl_Layout.h>
-#include <FL/Fl_Menu_Bar.h>
+#include <FL/Fl_Menu_Bar.H>
 #include <fl/Fl_Table_Data.h>
 #include <MHDate.h>
 #include <MHDebug.h>
@@ -249,6 +249,34 @@
 }
 
 
+/**
+ * Callback for file chooser
+ */
+void fc_callback(Fl_File_Chooser *fc, void *data)
+{
+	XTrader *xt = static_cast<XTrader *>(data);
+	const char *file = fc->value();
+
+	if (file && *file) {
+		MHDate date;
+		Import* import = 0;
+		double start = MHUtil::Time();
+
+		XTrader::StartWork (STRING(INFO_IMPORTING));
+		try {
+			import = new Import (file);
+			import->Read ();
+			char buffer[100];
+			snprintf (buffer, 99, "%s (%d %s / %.1fs) (%s=%d)", STRING(INFO_IMPORT_FINISHED), import->Rows(), STRING(ROWS), MHUtil::Time() - start, STRING(ERROR_), import->Errors());
+			XTrader::SetMessage (buffer);
+		}
+		catch (const char* message) {
+			XTrader::SetError (message);
+		}
+		XTrader::StopWork ("");
+		delete import;
+	}
+}
 
 /**
 *  Callback for all menu items
@@ -291,28 +319,11 @@
                 break;
 
             case Resource::MENU_IMPORT: {
-                char* file = fl_file_chooser (STRING(DLG_IMPORT), STRING(DLG_IMPORT_FILTER), "");
-                if (file && *file) {
-                    MHDate date;
-                    Import* import = 0;
-                    double start = MHUtil::Time();
-
-                    XTrader::StartWork (STRING(INFO_IMPORTING));
-                    try {
-                        import = new Import (file);
-                        import->Read ();
-                        char buffer[100];
-                        snprintf (buffer, 99, "%s (%d %s / %.1fs) (%s=%d)", STRING(INFO_IMPORT_FINISHED), import->Rows(), STRING(ROWS), MHUtil::Time() - start, STRING(ERROR_), import->Errors());
-                        XTrader::SetMessage (buffer);
-                    }
-                    catch (const char* message) {
-                        XTrader::SetError (message);
-                    }
-                    XTrader::StopWork ("");
-                    delete import;
-                    aListeners->Send (0, "Import", "changed", 0, 0);
-                    Fl::redraw ();
-                }
+                Fl_File_Chooser *fc = new Fl_File_Chooser (STRING(DLG_IMPORT), STRING(DLG_IMPORT_FILTER), Fl_File_Chooser::SINGLE, "");
+                fc->callback(fc_callback);
+                delete fc;
+                aListeners->Send (0, "Import", "changed", 0, 0);
+                Fl::redraw ();
                 break;
             }
 
