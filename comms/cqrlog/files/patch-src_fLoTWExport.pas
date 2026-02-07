--- src/fLoTWExport.pas.orig	2021-01-16 14:03:35 UTC
+++ src/fLoTWExport.pas
@@ -267,7 +267,7 @@ begin
   else begin
     WindowState := wsMaximized
   end;
-  edtTqsl.Text := cqrini.ReadString('LoTWExp','cmd','/usr/bin/tqsl -d -l "your qth name" %f -x');
+  edtTqsl.Text := cqrini.ReadString('LoTWExp','cmd','%%LOCALBASE%%/bin/tqsl -d -l "your qth name" %f -x');
   if pgLoTWExport.ActivePageIndex = 1 then
     rbWebExportNotExported.SetFocus
 end;
