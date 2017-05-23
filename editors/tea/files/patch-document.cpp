--- document.cpp.orig	2017-05-22 17:41:11 UTC
+++ document.cpp
@@ -2570,7 +2570,7 @@ void CTEAEdit::rect_sel_cut (bool just_d
   cursor.endEditBlock();
   
   if (! just_del)  
-     QApplication::clipboard()->setText (sl_copy.join ('\n'));
+     QApplication::clipboard()->setText (sl_copy.join ("\n"));
 }
 
 
