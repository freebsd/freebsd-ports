--- src/fLoTWExport.pas.orig	2018-06-17 12:42:42 UTC
+++ src/fLoTWExport.pas
@@ -250,7 +250,7 @@ begin
   else begin
     WindowState := wsMaximized
   end;
-  edtTqsl.Text := cqrini.ReadString('LoTWExp','cmd','/usr/bin/tqsl -d -l "your qth name" %f -x');
+  edtTqsl.Text := cqrini.ReadString('LoTWExp','cmd','%%LOCALBASE%%/bin/tqsl -d -l "your qth name" %f -x');
   if pgLoTWExport.ActivePageIndex = 1 then
     rbWebExportNotExported.SetFocus
 end;
