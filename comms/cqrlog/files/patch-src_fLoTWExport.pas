--- src/fLoTWExport.pas.orig	2014-06-30 23:38:20.000000000 -0700
+++ src/fLoTWExport.pas	2014-06-30 23:38:53.000000000 -0700
@@ -232,7 +232,7 @@
   else begin
     WindowState := wsMaximized
   end;
-  edtTqsl.Text := cqrini.ReadString('LoTWExp','cmd','/usr/bin/tqsl -d -l "your qth name" %f -x');
+  edtTqsl.Text := cqrini.ReadString('LoTWExp','cmd','%%LOCALBASE%%/bin/tqsl -d -l "your qth name" %f -x');
   if pgLoTWExport.ActivePageIndex = 1 then
     rbWebExportNotExported.SetFocus
 end;
