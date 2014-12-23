--- src/dUtils.pas.orig	2014-10-03 12:37:57.000000000 -0700
+++ src/dUtils.pas	2014-12-20 18:13:35.000000000 -0800
@@ -2380,7 +2380,7 @@
   proj: string = '';
 begin
   Result := '';
-  Result := cqrini.ReadString('xplanet', 'path', '/usr/bin/xplanet');
+  Result := cqrini.ReadString('xplanet', 'path', '%%LOCALBASE%%/xplanet');
   myloc := cqrini.ReadString('Station', 'LOC', '');
   if not FileExists(Result) then
   begin
@@ -2670,7 +2670,7 @@
   if Device = '' then
     exit;
 
-  cmd := cqrini.ReadString('TRX', 'Path', '/usr/bin/rigctld');
+  cmd := cqrini.ReadString('TRX', 'Path', '%%LOCALBASE%%/rigctld');
   if not FileExists(cmd) then
     exit;
   cmd := cmd + ' --model=' + rigid;
