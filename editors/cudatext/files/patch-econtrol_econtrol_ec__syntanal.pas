--- econtrol/econtrol/ec_syntanal.pas.orig	2026-10-31 03:47:26 UTC
+++ econtrol/econtrol/ec_syntanal.pas
@@ -4748,7 +4748,7 @@ begin
   // so both will be readable:
   //   CodeTemplates = <>
   //   CodeTemplates = < item ... end >
-  Reader.SkipValue;
+  Reader.Driver.SkipValue;
 end;
 
 procedure TecSyntAnalyzer.LoadExtraData(const AFileName: string);
