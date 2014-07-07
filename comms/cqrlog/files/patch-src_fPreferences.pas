--- src/fPreferences.pas.orig	2014-06-30 23:39:36.000000000 -0700
+++ src/fPreferences.pas	2014-06-30 23:39:52.000000000 -0700
@@ -2471,7 +2471,7 @@
   cb47GHz.Checked := cqrini.ReadBool('Bands', '47GHz', False);
   cb76GHz.Checked := cqrini.ReadBool('Bands', '76GHz', False);
 
-  edtRigCtldPath.Text := cqrini.ReadString('TRX', 'RigCtldPath', '/usr/bin/rigctld');
+  edtRigCtldPath.Text := cqrini.ReadString('TRX', 'RigCtldPath', '%%LOCALBASE%%/bin/rigctld');
 
   edtR1Device.Text := cqrini.ReadString('TRX1', 'device', '');
   edtRigID1.Text := cqrini.ReadString('TRX1', 'model', '');
@@ -2508,7 +2508,7 @@
   cmbDTRR2.ItemIndex := cqrini.ReadInteger('TRX2', 'DTR', 0);
   cmbRTSR2.ItemIndex := cqrini.ReadInteger('TRX2', 'RTS', 0);
 
-  edtRotCtldPath.Text := cqrini.ReadString('ROT', 'RotCtldPath', '/usr/bin/rotctld');
+  edtRotCtldPath.Text := cqrini.ReadString('ROT', 'RotCtldPath', '%%LOCALBASE%%/bin/rotctld');
 
   edtRot1Device.Text := cqrini.ReadString('ROT1', 'device', '');
   edtRot1ID.Text := cqrini.ReadString('ROT1', 'model', '');
@@ -2725,7 +2725,7 @@
   chkIgnoreBandFreq.Checked := cqrini.ReadBool('BandMap','IgnoreBandFreq',True);
   chkUseNewQSOFreqMode.Checked := cqrini.ReadBool('BandMap','UseNewQSOFreqMode',False);
 
-  edtXplanetPath.Text := cqrini.ReadString('xplanet', 'path', '/usr/bin/xplanet');
+  edtXplanetPath.Text := cqrini.ReadString('xplanet', 'path', '%%LOCALBASE%%/bin/xplanet');
   edtXHeight.Text := cqrini.ReadString('xplanet', 'height', '100');
   edtXWidth.Text := cqrini.ReadString('xplanet', 'width', '100');
   edtXTop.Text := cqrini.ReadString('xplanet', 'top', '10');
