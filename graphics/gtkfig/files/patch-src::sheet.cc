--- src/sheet.cc.orig	Mon Dec 23 04:01:02 2002
+++ src/sheet.cc	Mon Dec 23 04:01:05 2002
@@ -1142,7 +1142,7 @@
   if (!Obj->HasText()) return;
 
   OldText = ((TCADTextObject *)Obj)->GetText();
-  TextEditBox(OldText,NULL,EditTextCallback,this);
+  TextEditBox(OldText,NULL,(void(*)(char*,void*))EditTextCallback,this);
   free(OldText);
 }
 
