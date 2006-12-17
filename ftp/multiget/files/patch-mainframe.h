--- ./mainframe.h.orig	Thu Nov  9 03:11:21 2006
+++ ./mainframe.h	Sun Dec 17 16:45:04 2006
@@ -231,7 +231,7 @@
     void InitMeterBar();
 	bool CheckLocale(_MGLANG lang);
 	void CheckLangMenu(_MGLANG lang);
-	void MainFrame::NoLangSupport();
+	void NoLangSupport();
     //void CheckTempDir();
     void DoNewTask( wxString url, wxString refer = wxT( "" ), wxString savepath = wxT( "" ), wxString savefile = wxT( "" ) );
 
