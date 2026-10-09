--- src/fTRXControl.pas.orig	2026-09-25 09:42:16.000000000 -0700
+++ src/fTRXControl.pas	2026-09-29 09:04:05.935640000 -0700
@@ -1112,7 +1112,7 @@
     poll:=cqrini.ReadInteger('TRX' + RigInUse, dmUtils.PlatformKey('poll'), 500);
     if ((poll>60000) or (poll<10)) then  poll := 500;  //limit values
 
-  radio.RigCtldPath := cqrini.ReadString('TRX', dmUtils.PlatformKey('RigCtldPath'), dmUtils.DefaultToolPath('rigctld', '/usr/bin/rigctld'));
+  radio.RigCtldPath := cqrini.ReadString('TRX', dmUtils.PlatformKey('RigCtldPath'), dmUtils.DefaultToolPath('rigctld', '%%LOCALBASE%%/bin/rigctld'));
   radio.RigCtldArgs := dmUtils.GetRadioRigCtldCommandLine(StrToInt(RigInUse));
   radio.RunRigCtld := cqrini.ReadBool('TRX' + RigInUse, dmUtils.PlatformKey('RunRigCtld'), False);
   radio.RigDevice := cqrini.ReadString('TRX' + RigInUse, dmUtils.PlatformKey('device'), '');
