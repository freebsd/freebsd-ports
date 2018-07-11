--- src/dUtils.pas.orig	2018-06-17 12:42:42 UTC
+++ src/dUtils.pas
@@ -2376,7 +2376,7 @@ var
   proj: string = '';
 begin
   Result := '';
-  Result := cqrini.ReadString('xplanet', 'path', '/usr/bin/xplanet');
+  Result := cqrini.ReadString('xplanet', 'path', '%%LOCALBASE%%/bin/xplanet');
   myloc := cqrini.ReadString('Station', 'LOC', '');
   if not FileExists(Result) then
   begin
@@ -2667,7 +2667,7 @@ begin
   if Device = '' then
     exit;
 
-  cmd := cqrini.ReadString('TRX', 'Path', '/usr/bin/rigctld');
+  cmd := cqrini.ReadString('TRX', 'Path', '%%LOCALBASE%%/bin/rigctld');
   if not FileExists(cmd) then
     exit;
   cmd := cmd + ' --model=' + rigid;
