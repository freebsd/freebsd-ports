--- src/GUI/GUI_Clipboard.cpp.orig	2018-07-04 22:36:05 UTC
+++ src/GUI/GUI_Clipboard.cpp
@@ -131,6 +131,7 @@ bool			GUI_Clipboard_HasClipType(GUI_Cli
 		return (IsClipboardFormatAvailable(sCITs[inType]));
 	#else
 		#warning implement clipboard typecheck for linux
+		return true;
 	#endif
 }
 
@@ -209,6 +210,7 @@ int				GUI_Clipboard_GetSize(GUI_ClipTyp
 
 	#else
 		#warning implement clipboard GetSize for linux
+		return true;
 	#endif
 }
 
@@ -240,6 +242,7 @@ bool			GUI_Clipboard_GetData(GUI_ClipTyp
 
 	#else
 		#warning implement clipboard getData() for linux
+		return true;
 	#endif
 }
 bool			GUI_Clipboard_SetData(int type_count, GUI_ClipType inTypes[], int sizes[], const void * ptrs[])
@@ -279,6 +282,7 @@ bool			GUI_Clipboard_SetData(int type_co
 
 	#else
 		#warning implement clipboard setData() for linux
+		return true;
 	#endif
 }
 
@@ -326,6 +330,7 @@ bool			GUI_SetTextToClipboard(const stri
      QClipboard* cb = QApplication::clipboard();
      QString tex = QString::fromUtf8(inText.c_str());
       cb->setText(tex);
+	return true;
 	#endif
 }
 
