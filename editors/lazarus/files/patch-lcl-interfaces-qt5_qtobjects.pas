--- lcl/interfaces/qt5/qtobjects.pas	2020-11-23 21:01:09.916716000 -0500
+++ lcl/interfaces/qt5/qtobjects.pas	2020-11-23 21:02:33.484592000 -0500
@@ -3115,8 +3115,9 @@
   SelFont := AFont;
   if (AFont.FHandle <> nil) and (Widget <> nil) then
   begin
-    QFnt := QPainter_font(Widget);
-    AssignQtFont(AFont.FHandle, QFnt);
+    QFnt := QFont_Create(AFont.FHandle);
+    QPainter_setFont(Widget, QFnt);
+    QFont_destroy(QFnt);
     vFont.Angle := AFont.Angle;
   end;
 end;
