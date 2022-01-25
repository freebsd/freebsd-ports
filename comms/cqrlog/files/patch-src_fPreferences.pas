--- src/fPreferences.pas.orig	2021-01-16 14:03:35 UTC
+++ src/fPreferences.pas
@@ -2818,11 +2818,11 @@ begin
   cb47GHz.Checked := cqrini.ReadBool('Bands', '47GHz', False);
   cb76GHz.Checked := cqrini.ReadBool('Bands', '76GHz', False);
 
-  edtRigCtldPath.Text := cqrini.ReadString('TRX', 'RigCtldPath', '/usr/bin/rigctld');
+  edtRigCtldPath.Text := cqrini.ReadString('TRX', 'RigCtldPath', '%%LOCALBASE%%/bin/rigctld');
   chkTrxControlDebug.Checked := cqrini.ReadBool('TRX','Debug',False);
   chkModeRelatedOnly.Checked := cqrini.ReadBool('TRX','MemModeRelated',False);
 
-  edtRotCtldPath.Text := cqrini.ReadString('ROT', 'RotCtldPath', '/usr/bin/rotctld');
+  edtRotCtldPath.Text := cqrini.ReadString('ROT', 'RotCtldPath', '%%LOCALBASE%%/bin/rotctld');
 
   if (FileExistsUTF8(edtRigCtldPath.Text)) then
   begin
@@ -3039,7 +3039,7 @@ begin
   seFreqWidth.Value := cqrini.ReadInteger('BandMapFilter','FreqWidth',12);
   seCallWidth.Value := cqrini.ReadInteger('BandMapFilter','CallWidth',12);
 
-  edtXplanetPath.Text := cqrini.ReadString('xplanet', 'path', '/usr/bin/xplanet');
+  edtXplanetPath.Text := cqrini.ReadString('xplanet', 'path', '%%LOCALBASE%%/bin/xplanet');
   edtXHeight.Text := cqrini.ReadString('xplanet', 'height', '100');
   edtXWidth.Text := cqrini.ReadString('xplanet', 'width', '100');
   edtXTop.Text := cqrini.ReadString('xplanet', 'top', '10');
