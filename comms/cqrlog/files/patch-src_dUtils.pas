--- src/dUtils.pas.orig	2021-01-16 14:03:35 UTC
+++ src/dUtils.pas
@@ -2603,7 +2603,7 @@ var
   proj: string = '';
 begin
   Result := '';
-  Result := cqrini.ReadString('xplanet', 'path', '/usr/bin/xplanet');
+  Result := cqrini.ReadString('xplanet', 'path', '%%LOCALBASD%%/bin/xplanet');
   myloc := cqrini.ReadString('Station', 'LOC', '');
   customloc := cqrini.ReadString('xplanet', 'loc', '');
   if not FileExists(Result) then
@@ -2953,7 +2953,7 @@ begin
   if Device = '' then
     exit;
 
-  cmd := cqrini.ReadString('TRX', 'Path', '/usr/bin/rigctld');
+  cmd := cqrini.ReadString('TRX', 'Path', '%%LOCALBASE%%/bin/rigctld');
   if not FileExists(cmd) then
     exit;
   cmd := cmd + ' --model=' + rigid;
@@ -3855,7 +3855,7 @@ end;
 
 function TdmUtils.GetNewQSOCaption(capt: string): string;
 begin
-  Result := capt + ' ... (CQRLOG for Linux)';
+  Result := capt + ' ... (CQRLOG for FreeBSD)';
   if dmData.LogName <> '' then
     Result := Result + ', database: ' + dmData.LogName;
 end;
