--- src/dUtils.pas.orig	2026-09-25 09:42:16.000000000 -0700
+++ src/dUtils.pas	2026-09-29 19:55:58.711413000 -0700
@@ -2532,7 +2532,7 @@
   proj: string = '';
 begin
   Result := '';
-  Result := cqrini.ReadString('xplanet', PlatformKey('path'), DefaultToolPath('xplanet', '/usr/bin/xplanet'));
+  Result := cqrini.ReadString('xplanet', PlatformKey('path'), DefaultToolPath('xplanet', '%%LOCALBASE%%/bin/xplanet'));
   myloc := cqrini.ReadString('Station', 'LOC', '');
   customloc := cqrini.ReadString('xplanet', 'loc', '');
   //Inside Flatpak xplanet lives on the host, so the sandbox cannot stat it;
@@ -2899,7 +2899,7 @@
   if Device = '' then
     exit;
 
-  cmd := cqrini.ReadString('TRX', PlatformKey('RigCtldPath'), DefaultToolPath('rigctld', '/usr/bin/rigctld'));
+  cmd := cqrini.ReadString('TRX', PlatformKey('RigCtldPath'), DefaultToolPath('rigctld', '%%LOCALBASE%%/bin/rigctld'));
   if not FileExists(cmd) then
     exit;
   cmd := cmd + ' --model=' + rigid;
@@ -3542,7 +3542,7 @@
   // full path: RunOnBackground only starts executables it can FileExists()
   RunOnBackground('/usr/bin/open ' + Target);
   {$ELSE}
-  RunOnBackground('xdg-open ' + Target);
+  RunOnBackground('%%LOCALBASE%%/bin/xdg-open ' + Target);
   {$ENDIF}
 end;
 
@@ -3584,7 +3584,7 @@
   //rotctld lives in the same directory as rigctld. Derive the rotctld default
   //from the effective rigctld path (saved value or its own default) and just
   //swap the binary name, so rotctld follows rigctld (app bundle / system / homebrew).
-  rigCtldPath := cqrini.ReadString('TRX', PlatformKey('RigCtldPath'), DefaultToolPath('rigctld', '/usr/bin/rigctld'));
+  rigCtldPath := cqrini.ReadString('TRX', PlatformKey('RigCtldPath'), DefaultToolPath('rigctld', '%%LOCALBASE%%/bin/rigctld'));
   Result := ExtractFilePath(rigCtldPath) + 'rotctld';
 end;
 
@@ -4091,7 +4091,7 @@
 
 function TdmUtils.GetNewQSOCaption(capt: string): string;
 begin
-  Result := capt + ' ... (CQRLOG for Linux)';
+  Result := capt + ' ... (CQRLOG for FreeBSD/Linux)';
   if dmData.LogName <> '' then
     Result := Result + ', database: ' + dmData.LogName;
 end;
