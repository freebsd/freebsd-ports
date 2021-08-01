--- Source/FrameEditView.pas.orig	2021-08-01 06:56:07 UTC
+++ Source/FrameEditView.pas
@@ -438,9 +438,6 @@ begin
   ed.OnCommandProcessed:=@edCommandProcessed;  //necesita para actualizar el cursor
 //  RecentFiles := TStringList.Create;
   MaxRecents := 1;   //Inicia con 1
-  //guarda parámetros
-  nomDef := nomDef0;
-  extDef := extDef0;
   NewFile;   //Inicia editor con archivo vacío
   ///////////////////////////////////////////////////////////////
   tabWidth := 30;  //valor por defecto
@@ -848,7 +845,6 @@ begin
   ed.OnChangeEditorState := @ChangeEditorState;
   ed.OnChangeFileInform := @editChangeFileInform;
   ed.hl.IconList := ImgCompletion;
-  ed.SetLanguage(curLanguage);
   //Configura PageControl
   ed.SynEdit.Parent := self;
   ed.SynEdit.Align := alClient;
