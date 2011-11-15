--- ./xtrader/src/dlg/DownloadDlg.h.orig	2004-11-14 11:21:35.000000000 +0100
+++ ./xtrader/src/dlg/DownloadDlg.h	2011-11-15 13:46:19.000000000 +0100
@@ -18,6 +18,7 @@
 #include <download/BaseDownload.h>
 
 class Report;
+class Fl_File_Chooser;
 
 
 
@@ -51,6 +52,8 @@
     Fl_Button*              aClose;
 
     void                    download (int type, const char* start, const char* stop, int action);
+
+	 friend void dlg_fc_callback(Fl_File_Chooser *fc, void *data);
 };
 
 #endif
