--- src/dUtils.pas.orig	2016-04-20 16:06:15 UTC
+++ src/dUtils.pas
@@ -2394,7 +2394,7 @@ var
   proj: string = '';
 begin
   Result := '';
-  Result := cqrini.ReadString('xplanet', 'path', '/usr/bin/xplanet');
+  Result := cqrini.ReadString('xplanet', 'path', '%%LOCALBASE%%/bin/xplanet');
   myloc := cqrini.ReadString('Station', 'LOC', '');
   if not FileExists(Result) then
   begin
@@ -2684,7 +2684,7 @@ begin
   if Device = '' then
     exit;
 
-  cmd := cqrini.ReadString('TRX', 'Path', '/usr/bin/rigctld');
+  cmd := cqrini.ReadString('TRX', 'Path', '%%LOCALBASE%%/bin/rigctld');
   if not FileExists(cmd) then
     exit;
   cmd := cmd + ' --model=' + rigid;
