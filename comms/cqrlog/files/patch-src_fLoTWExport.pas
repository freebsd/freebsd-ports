--- src/fLoTWExport.pas.orig	2026-09-25 09:42:16.000000000 -0700
+++ src/fLoTWExport.pas	2026-09-29 08:39:53.098136000 -0700
@@ -260,7 +260,7 @@
   else begin
     WindowState := wsMaximized
   end;
-  edtTqsl.Text := cqrini.ReadString('LoTWExp', dmUtils.PlatformKey('cmd'), dmUtils.DefaultToolPath('tqsl', '/usr/bin/tqsl') + ' -d -l "your qth name" %f -x');
+  edtTqsl.Text := cqrini.ReadString('LoTWExp', dmUtils.PlatformKey('cmd'), dmUtils.DefaultToolPath('tqsl', '%%LOCALBASE%%/bin/tqsl') + ' -d -l "your qth name" %f -x');
   if pgLoTWExport.ActivePageIndex = 1 then
     rbWebExportNotExported.SetFocus
 end;
