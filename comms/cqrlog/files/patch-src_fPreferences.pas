--- src/fPreferences.pas.orig	2026-09-25 09:42:16.000000000 -0700
+++ src/fPreferences.pas	2026-09-29 08:58:32.873429000 -0700
@@ -2651,8 +2651,8 @@
 Begin
      Result :='';
      Label17.Caption:='NOTE: You have to give full path for program file names!';
-     {$IFDEF DARWIN}
-     odFindBrowser.InitialDir:='/usr/local/bin';
+     {$IF Defined(DARWIN) or Defined(FREEBSD)}
+     odFindBrowser.InitialDir:='%%LOCALBASE%%/bin';
      {$ELSE}
      odFindBrowser.InitialDir:='/usr/bin';
      {$ENDIF}
@@ -2745,8 +2745,8 @@
 
 procedure TfrmPreferences.edtWebBrowserClick(Sender: TObject);
 Begin
-  {$IFDEF DARWIN}
-  odFindBrowser.InitialDir:='/usr/local/bin';
+  {$IF Defined(DARWIN) or Defined(FREEBSD)}
+  odFindBrowser.InitialDir:='%%LOCALBASE%%/bin';
   {$ELSE}
   odFindBrowser.InitialDir:='/usr/bin';
   {$ENDIF}
@@ -2971,7 +2971,7 @@
   cb134GHz.Checked := cqrini.ReadBool('Bands', '134GHz', False);
   cb241GHz.Checked := cqrini.ReadBool('Bands', '241GHz', False);
 
-  edtRigCtldPath.Text := cqrini.ReadString('TRX', dmUtils.PlatformKey('RigCtldPath'), dmUtils.DefaultToolPath('rigctld', '/usr/bin/rigctld'));
+  edtRigCtldPath.Text := cqrini.ReadString('TRX', dmUtils.PlatformKey('RigCtldPath'), dmUtils.DefaultToolPath('rigctld', '%%LOCALBASE%%/bin/rigctld'));
   chkTrxControlDebug.Checked := cqrini.ReadBool('TRX', dmUtils.PlatformKey('Debug'), False);
   chkModeRelatedOnly.Checked := cqrini.ReadBool('TRX', dmUtils.PlatformKey('MemModeRelated'), False);
   edtRigCount.Value:=cqrini.ReadInteger('TRX', dmUtils.PlatformKey('RigCount'), 2);
@@ -3145,7 +3145,7 @@
   seFreqWidth.Value := cqrini.ReadInteger('BandMapFilter','FreqWidth',12);
   seCallWidth.Value := cqrini.ReadInteger('BandMapFilter','CallWidth',12);
 
-  edtXplanetPath.Text := cqrini.ReadString('xplanet', dmUtils.PlatformKey('path'), dmUtils.DefaultToolPath('xplanet', '/usr/bin/xplanet'));
+  edtXplanetPath.Text := cqrini.ReadString('xplanet', dmUtils.PlatformKey('path'), dmUtils.DefaultToolPath('xplanet', '%%LOCALBASE%%/bin/xplanet'));
   edtXHeight.Text := cqrini.ReadString('xplanet', 'height', '100');
   edtXWidth.Text := cqrini.ReadString('xplanet', 'width', '100');
   edtXTop.Text := cqrini.ReadString('xplanet', 'top', '10');
@@ -3412,7 +3412,7 @@
    rp  :string;
 Begin
   nr:=IntToStr(RigNr);
-  rp:= cqrini.ReadString('TRX', dmUtils.PlatformKey('RigCtldPath'), dmUtils.DefaultToolPath('rigctld', '/usr/bin/rigctld'));
+  rp:= cqrini.ReadString('TRX', dmUtils.PlatformKey('RigCtldPath'), dmUtils.DefaultToolPath('rigctld', '%%LOCALBASE%%/bin/rigctld'));
   if FileExistsUTF8(rp) then
     dmUtils.LoadRigsToComboBox(cqrini.ReadString('TRX'+nr, dmUtils.PlatformKey('model'), ''),rp,cmbModelRig)
   else begin
