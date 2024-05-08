--- lcl/interfaces/qt5/qtwidgets.pas.orig	2024-05-04 04:39:55 UTC
+++ lcl/interfaces/qt5/qtwidgets.pas
@@ -10213,7 +10213,7 @@ begin
 
 procedure TQtTextEdit.setReadOnly(const AReadOnly: Boolean);
 begin
-  {$IFDEF DARWIN} // issue #40246
+  {$IF DEFINED(DARWIN) OR DEFINED(FREEBSD)} // issue #40246
   if AReadOnly <> QTextEdit_isReadOnly(QTextEditH(Widget)) then
   {$ENDIF}
     QTextEdit_setReadOnly(QTextEditH(Widget), AReadOnly);
