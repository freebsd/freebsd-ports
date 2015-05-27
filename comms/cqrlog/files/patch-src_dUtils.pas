--- src/dUtils.pas.orig	2015-03-04 15:17:21 UTC
+++ src/dUtils.pas
@@ -2381,7 +2381,7 @@ var
   proj: string = '';
 begin
   Result := '';
-  Result := cqrini.ReadString('xplanet', 'path', '/usr/bin/xplanet');
+  Result := cqrini.ReadString('xplanet', 'path', '%%LOCALBASE%%/xplanet');
   myloc := cqrini.ReadString('Station', 'LOC', '');
   if not FileExists(Result) then
   begin
@@ -2671,7 +2671,7 @@ begin
   if Device = '' then
     exit;
 
-  cmd := cqrini.ReadString('TRX', 'Path', '/usr/bin/rigctld');
+  cmd := cqrini.ReadString('TRX', 'Path', '%%LOCALBASE%%/rigctld');
   if not FileExists(cmd) then
     exit;
   cmd := cmd + ' --model=' + rigid;
