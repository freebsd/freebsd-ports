--- src/fTRXControl.pas.orig	2015-03-04 15:17:21 UTC
+++ src/fTRXControl.pas
@@ -660,7 +660,7 @@ begin
   else
     radio.RigId := id;
   //Writeln('huu4');
-  radio.RigCtldPath := cqrini.ReadString('TRX','RigCtldPath','/usr/bin/rigctld');
+  radio.RigCtldPath := cqrini.ReadString('TRX','RigCtldPath','%%LOCALBASE%%/bin/rigctld');
   radio.RigCtldArgs := dmUtils.GetRadioRigCtldCommandLine(StrToInt(n));
   radio.RunRigCtld  := cqrini.ReadBool('TRX'+n,'RunRigCtld',False);
   radio.RigDevice   := cqrini.ReadString('TRX'+n,'device','');
