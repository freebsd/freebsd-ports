--- lcl/interfaces/qt6/qtwidgets.pas.orig	2024-05-04 05:06:13 UTC
+++ lcl/interfaces/qt6/qtwidgets.pas
@@ -10243,7 +10243,10 @@ begin
 
 procedure TQtTextEdit.setReadOnly(const AReadOnly: Boolean);
 begin
-  QTextEdit_setReadOnly(QTextEditH(Widget), AReadOnly);
+  {$IF DEFINED(DARWIN) OR DEFINED(FREEBSD)} // issue #40246
+  if AReadOnly <> QTextEdit_isReadOnly(QTextEditH(Widget)) then
+  {$ENDIF}
+    QTextEdit_setReadOnly(QTextEditH(Widget), AReadOnly);
 end;
 
 procedure TQtTextEdit.setSelection(const AStart, ALength: Integer);
