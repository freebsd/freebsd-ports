--- ./xtrader/src/dlg/ExportDlg.h.orig	2004-11-14 11:21:35.000000000 +0100
+++ ./xtrader/src/dlg/ExportDlg.h	2011-11-15 13:46:19.000000000 +0100
@@ -16,6 +16,7 @@
 #include <FL/Fl_Button.H>
 
 class Report;
+class Fl_File_Chooser;
 
 
 
@@ -45,6 +46,8 @@
     Fl_Button*              aBrowse;
     Fl_Button*              aHelp;
     Fl_Button*              aClose;
+
+	 friend void exp_fc_callback(Fl_File_Chooser *fc, void *data);
 };
 
 #endif
