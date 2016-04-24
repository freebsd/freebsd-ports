--- src/fPreferences.pas.orig	2016-04-20 16:06:15 UTC
+++ src/fPreferences.pas
@@ -2506,7 +2506,7 @@ begin
   cb47GHz.Checked := cqrini.ReadBool('Bands', '47GHz', False);
   cb76GHz.Checked := cqrini.ReadBool('Bands', '76GHz', False);
 
-  edtRigCtldPath.Text := cqrini.ReadString('TRX', 'RigCtldPath', '/usr/bin/rigctld');
+  edtRigCtldPath.Text := cqrini.ReadString('TRX', 'RigCtldPath', '%%LOCALBASE%%/bin/rigctld');
   chkTrxControlDebug.Checked := cqrini.ReadBool('TRX','Debug',False);
   chkModeRelatedOnly.Checked := cqrini.ReadBool('TRX','MemModeRelated',False);
 
@@ -2552,7 +2552,7 @@ begin
   cmbDTRR2.ItemIndex := cqrini.ReadInteger('TRX2', 'DTR', 0);
   cmbRTSR2.ItemIndex := cqrini.ReadInteger('TRX2', 'RTS', 0);
 
-  edtRotCtldPath.Text := cqrini.ReadString('ROT', 'RotCtldPath', '/usr/bin/rotctld');
+  edtRotCtldPath.Text := cqrini.ReadString('ROT', 'RotCtldPath', '%%LOCALBASE%%/bin/rotctld');
 
   edtRot1Device.Text := cqrini.ReadString('ROT1', 'device', '');
   edtRot1ID.Text := cqrini.ReadString('ROT1', 'model', '');
@@ -2701,7 +2701,7 @@ begin
   chkUseNewQSOFreqMode.Checked := cqrini.ReadBool('BandMap','UseNewQSOFreqMode',False);
   chkPlusToBandMap.Checked := cqrini.ReadBool('BandMap','PlusToBandMap',False);
 
-  edtXplanetPath.Text := cqrini.ReadString('xplanet', 'path', '/usr/bin/xplanet');
+  edtXplanetPath.Text := cqrini.ReadString('xplanet', 'path', '%%LOCALBASE%%/bin/xplanet');
   edtXHeight.Text := cqrini.ReadString('xplanet', 'height', '100');
   edtXWidth.Text := cqrini.ReadString('xplanet', 'width', '100');
   edtXTop.Text := cqrini.ReadString('xplanet', 'top', '10');
