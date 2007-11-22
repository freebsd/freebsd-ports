--- common/AboutDlg.cpp.orig	2007-11-13 22:57:56.000000000 +0100
+++ common/AboutDlg.cpp	2007-11-13 22:59:13.000000000 +0100
@@ -290,11 +290,11 @@
 void AboutDialog(void)
 {
 	void *wid = UCreate_AboutDlg();
-	UStr  appText = UCvsApp::gApp->GetAppName();
+	const UStr  appText = UCvsApp::gApp->GetAppName();
 		
 	UAboutDlg *dlg = new UAboutDlg ();
 	UEventSendMessage(dlg->GetWidID(), EV_INIT_WIDGET, kUMainWidget, wid);	
-	UEventSendMessage(dlg->GetWidID(), EV_SETTEXT, kUMainWidget, appText);	
+	UEventSendMessage(dlg->GetWidID(), EV_SETTEXT, kUMainWidget, (const char *)appText);	
 	
 	bool res = false;
 	
