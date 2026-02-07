--- src/HexEditorCtrl/wxHexCtrl/main.cpp.orig	2017-12-31 02:15:18 UTC
+++ src/HexEditorCtrl/wxHexCtrl/main.cpp
@@ -60,7 +60,7 @@ MyFrame::MyFrame(wxFrame *frame, const wxString& title
 #endif // wxUSE_STATUSBAR
 
 	wxString ch;
-	for(int j=0 ; j < 90 ; j++ ){
+	for(char j=0 ; j < 90 ; j++ ){
 			ch.Append(j);
 	hex_ctrl->SetBinValue( ch.char_str(),90,true );
 	}
