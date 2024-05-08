--- lcl/interfaces/qt6/qtwidgets.pas.orig	2024-05-04 04:27:27 UTC
+++ lcl/interfaces/qt6/qtwidgets.pas
@@ -10245,7 +10245,7 @@ end;
 
 procedure TQtTextEdit.setReadOnly(const AReadOnly: Boolean);
 begin
-  {$IFDEF DARWIN} // issue #40246
+  {$IF DEFINED(DARWIN) OR DEFINED(FREEBSD)} // issue #40246
   if AReadOnly <> QTextEdit_isReadOnly(QTextEditH(Widget)) then
   {$ENDIF}
     QTextEdit_setReadOnly(QTextEditH(Widget), AReadOnly);
