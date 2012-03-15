--- Source/Core/DolphinWX/Src/LogWindow.h.orig	2012-03-14 18:12:23.066269697 +0100
+++ Source/Core/DolphinWX/Src/LogWindow.h	2012-03-14 18:12:36.531263827 +0100
@@ -79,7 +79,7 @@
 
 	DECLARE_EVENT_TABLE()
 
-	wxTextCtrl * CreateTextCtrl(wxPanel* parent, wxWindowID id = wxID_ANY, long Style = NULL);
+	wxTextCtrl * CreateTextCtrl(wxPanel* parent, wxWindowID id = wxID_ANY, long Style = 0);
 	void CreateGUIControls();
 	void PopulateBottom();
 	void UnPopulateBottom();
