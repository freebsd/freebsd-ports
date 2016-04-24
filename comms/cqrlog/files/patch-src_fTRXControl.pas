--- src/fTRXControl.pas.orig	2016-04-20 16:06:15 UTC
+++ src/fTRXControl.pas
@@ -749,7 +749,7 @@ begin
   if not TryStrToInt(cqrini.ReadString('TRX'+n,'poll','500'),poll) then
     poll := 500;
 
-  radio.RigCtldPath := cqrini.ReadString('TRX','RigCtldPath','/usr/bin/rigctld');
+  radio.RigCtldPath := cqrini.ReadString('TRX','RigCtldPath','%%LOCALBASE%%/bin/rigctld');
   radio.RigCtldArgs := dmUtils.GetRadioRigCtldCommandLine(StrToInt(n));
   radio.RunRigCtld  := cqrini.ReadBool('TRX'+n,'RunRigCtld',False);
   radio.RigDevice   := cqrini.ReadString('TRX'+n,'device','');
