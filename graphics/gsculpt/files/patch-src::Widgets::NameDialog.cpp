--- ./src/Widgets/NameDialog.cpp.orig	Mon Jul 21 19:27:45 2003
+++ ./src/Widgets/NameDialog.cpp	Mon Jul 21 19:28:18 2003
@@ -44,8 +44,8 @@
 }
 
 NameDialog::NameDialog(NameDialogListener *l,
-							  const string& title = "Name",
-							  const string& prompt = "name:")
+							  const string& title,
+							  const string& prompt )
 {
 	listener = l;
 	constructorCommon(title, prompt);
