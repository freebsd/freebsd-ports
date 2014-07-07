--- src/dUtils.pas.orig	2014-06-30 23:37:31.000000000 -0700
+++ src/dUtils.pas	2014-06-30 23:38:03.000000000 -0700
@@ -2229,7 +2229,7 @@
   proj   : String = '';
 begin
   Result := '';
-  Result := cqrini.ReadString('xplanet','path','/usr/bin/xplanet');
+  Result := cqrini.ReadString('xplanet','path','%%LOCALBASE%%/bin/xplanet');
   myloc  := cqrini.ReadString('Station','LOC','');
   if not FileExists(Result) then
   begin
@@ -2502,7 +2502,7 @@
   if Device = '' then
     exit;
 
-  cmd := cqrini.ReadString('TRX','Path','/usr/bin/rigctld');
+  cmd := cqrini.ReadString('TRX','Path','%%LOCALBASE%%/bin/rigctld');
   if not FileExists(cmd) then
     exit;
   cmd := cmd+' --model='+rigid;
