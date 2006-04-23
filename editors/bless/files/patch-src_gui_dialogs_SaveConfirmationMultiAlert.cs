--- src/gui/dialogs/SaveConfirmationMultiAlert.cs.orig	Mon Feb  7 06:46:46 2005
+++ src/gui/dialogs/SaveConfirmationMultiAlert.cs	Fri Apr 14 21:04:08 2006
@@ -80,8 +80,7 @@
 			tv.AppendColumn ("Name", new CellRendererText(), "text", 1);
 			
 			foreach (SaveFileItem item in list) {
-				item.Save=true;
-				store.AppendValues(item.Save, item.Name);	
+				store.AppendValues(true, item.Name);	
 			}
 			 
 			return tv;
