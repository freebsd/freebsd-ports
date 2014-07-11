--- src/fTRXControl.pas.orig	2014-06-30 23:40:59.000000000 -0700
+++ src/fTRXControl.pas	2014-06-30 23:41:05.000000000 -0700
@@ -658,7 +658,7 @@
   else
     radio.RigId := id;
   //Writeln('huu4');
-  radio.RigCtldPath := cqrini.ReadString('TRX','RigCtldPath','/usr/bin/rigctld');
+  radio.RigCtldPath := cqrini.ReadString('TRX','RigCtldPath','%%LOCALBASE%%/bin/rigctld');
   radio.RigCtldArgs := dmUtils.GetRadioRigCtldCommandLine(StrToInt(n));
   radio.RunRigCtld  := cqrini.ReadBool('TRX'+n,'RunRigCtld',False);
   radio.RigDevice   := cqrini.ReadString('TRX'+n,'device','');
