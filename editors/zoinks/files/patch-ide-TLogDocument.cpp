--- ide/TLogDocument.cpp.orig	2007-11-03 00:04:36.000000000 +0100
+++ ide/TLogDocument.cpp	2007-11-03 00:09:52.000000000 +0100
@@ -262,7 +262,7 @@
 
 void TLogDocument::ClearText()
 {
-	fTextView->SetText("");
+	fTextView->SetText((char *)"");
 }
 
 
