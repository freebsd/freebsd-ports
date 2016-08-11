--- src/fLoTWExport.pas.orig	2016-04-20 16:06:15 UTC
+++ src/fLoTWExport.pas
@@ -235,7 +235,7 @@ begin
   else begin
     WindowState := wsMaximized
   end;
-  edtTqsl.Text := cqrini.ReadString('LoTWExp','cmd','/usr/bin/tqsl -d -l "your qth name" %f -x');
+  edtTqsl.Text := cqrini.ReadString('LoTWExp','cmd','%%LOCALBASE%%/bin/tqsl -d -l "your qth name" %f -x');
   if pgLoTWExport.ActivePageIndex = 1 then
     rbWebExportNotExported.SetFocus
 end;
