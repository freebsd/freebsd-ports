--- do_sql.cc.orig	Wed Apr 11 12:12:19 2001
+++ do_sql.cc	Thu Sep  4 02:17:56 2003
@@ -1,3 +1,5 @@
+#include <FL/Enumerations.H>
+#undef frame
 #include <FL/Flv_Table.H>
 #include <FL/Flve_Input.H>
 #include <FL/Fl_Window.H>
@@ -5,10 +7,15 @@
 #include <FL/Fl_Pixmap.H>
 #include <FL/Fl_Check_Button.H>
 #include <FL/Fl_Round_Button.H>
+#define filename_setext fl_filename_setext
 #include "bebac.h"
 #include <sqlplus.hh>
 #include <ctype.h>
-extern string real_sql; extern enum ios::open_mode how_to_open; extern char *pass;
+#include <iostream>
+using namespace std;
+extern string real_sql;
+extern enum ios::open_mode how_to_open;
+extern char *pass;
 #define depth       18
 #define minmin       5
 #define fontsize    14
