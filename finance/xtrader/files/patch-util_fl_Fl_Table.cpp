--- ./util/fl/Fl_Table.cpp.orig	2004-11-14 11:21:29.000000000 +0100
+++ ./util/fl/Fl_Table.cpp	2011-11-15 13:46:19.000000000 +0100
@@ -10,15 +10,15 @@
 #include "Fl_Select.h"
 #include "Fl_Find.h"
 #include "Fl_Defines.h"
-#include <FL/Fl.h>
-#include <FL/fl_ask.h>
-#include <FL/fl_draw.h>
-#include <FL/Fl_Choice.h>
-#include <FL/Fl_Check_Button.h>
-#include <FL/Fl_File_Chooser.h>
-#include <FL/Fl_Input.h>
-#include <FL/Fl_Scrollbar.h>
-#include <FL/fl_show_colormap.h>
+#include <FL/Fl.H>
+#include <FL/fl_ask.H>
+#include <FL/fl_draw.H>
+#include <FL/Fl_Choice.H>
+#include <FL/Fl_Check_Button.H>
+#include <FL/Fl_File_Chooser.H>
+#include <FL/Fl_Input.H>
+#include <FL/Fl_Scrollbar.H>
+#include <FL/fl_show_colormap.H>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -962,7 +962,14 @@
     }
 }
 
-
+/**
+ * Callback for file chooser
+ */
+void tab_fc_callback(Fl_File_Chooser *fc, void *data)
+{
+	Fl_Table *t = static_cast<Fl_Table *>(data);
+	t->aData->value (fc->value(), t->aCurrRow, t->aCurrCol);
+}
 
 /**
 *  Start to edit a cell
@@ -983,9 +990,10 @@
 
     }
     else if (aData->editor_type (aCurrRow, aCurrCol, false) == FL_DLG_FILE_EDITOR) {
-        char* file = fl_file_chooser("Select File", "*", aData->value(aCurrRow, aCurrCol));
-        aData->value (file, aCurrRow, aCurrCol);
 
+        Fl_File_Chooser *fc = new Fl_File_Chooser("Select File", "*", Fl_File_Chooser::SINGLE, aData->value(aCurrRow, aCurrCol));
+        fc->callback(tab_fc_callback, this);
+        delete fc;
     }
     else {
         aEditWidget = aData->editor (aCurrRow, aCurrCol, force_custom);
