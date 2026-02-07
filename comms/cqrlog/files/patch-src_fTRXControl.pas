--- src/fTRXControl.pas.orig	2021-01-16 14:03:35 UTC
+++ src/fTRXControl.pas
@@ -1096,7 +1096,7 @@ begin
   if not TryStrToInt(cqrini.ReadString('TRX'+n,'poll','500'),poll) then
     poll := 500;
 
-  radio.RigCtldPath := cqrini.ReadString('TRX','RigCtldPath','/usr/bin/rigctld');
+  radio.RigCtldPath := cqrini.ReadString('TRX','RigCtldPath','%%LOCALBASE%%/bin/rigctld');
   radio.RigCtldArgs := dmUtils.GetRadioRigCtldCommandLine(StrToInt(n));
   radio.RunRigCtld  := cqrini.ReadBool('TRX'+n,'RunRigCtld',False);
   radio.RigDevice   := cqrini.ReadString('TRX'+n,'device','');
