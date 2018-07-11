--- src/fTRXControl.pas.orig	2018-06-17 12:42:42 UTC
+++ src/fTRXControl.pas
@@ -856,7 +856,7 @@ begin
   if not TryStrToInt(cqrini.ReadString('TRX'+n,'poll','500'),poll) then
     poll := 500;
 
-  radio.RigCtldPath := cqrini.ReadString('TRX','RigCtldPath','/usr/bin/rigctld');
+  radio.RigCtldPath := cqrini.ReadString('TRX','RigCtldPath','%%LOCALBASE%%/bin/rigctld');
   radio.RigCtldArgs := dmUtils.GetRadioRigCtldCommandLine(StrToInt(n));
   radio.RunRigCtld  := cqrini.ReadBool('TRX'+n,'RunRigCtld',False);
   radio.RigDevice   := cqrini.ReadString('TRX'+n,'device','');
