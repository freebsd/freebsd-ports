--- src/DemodLabelDialog.cpp.orig	2019-02-25 02:53:22 UTC
+++ src/DemodLabelDialog.cpp
@@ -83,7 +83,7 @@ void DemodLabelDialog::OnChar(wxKeyEvent& event) {
 
     }
     else {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         dialogText->OnChar(event);
         event.Skip();
 #else
