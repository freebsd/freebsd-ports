--- ./util/fl/Fl_Table.h.orig	2004-11-14 11:21:34.000000000 +0100
+++ ./util/fl/Fl_Table.h	2011-11-15 13:46:19.000000000 +0100
@@ -12,12 +12,13 @@
     #define snprintf _snprintf
 #endif
 
-#include <FL/Fl_Group.h>
+#include <FL/Fl_Group.H>
 #include "Fl_Table_Data.h"
 
 class Fl_Input;
 class Fl_Scrollbar;
 class Fl_Find;
+class Fl_File_Chooser;
 
 enum {
     FL_DATA_CHANGE = 1000,
@@ -121,6 +122,8 @@
     void                    get_cell_pos (int& row, int& col, int& xpos, int& ypos, int& width, int& height);
     void                    start_edit_mode (bool force = false);
     void                    set_cursor(int row, int col) {move_cursor (row - aCurrRow, col - aCurrCol);}
+	 friend                  void tab_fc_callback(Fl_File_Chooser *fc, void *data);
+
 };
 
 #endif
