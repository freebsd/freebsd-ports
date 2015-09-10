--- src/fRotControl.pas.orig	2015-03-04 15:17:21 UTC
+++ src/fRotControl.pas
@@ -137,7 +137,7 @@ begin
     rotor.RotId := 1
   else
     rotor.RotId := id;
-  rotor.RotCtldPath := cqrini.ReadString('ROT','RigCtldPath','/usr/bin/rotctld');
+  rotor.RotCtldPath := cqrini.ReadString('ROT','RigCtldPath','%%LOCALBASE%%/bin/rotctld');
   rotor.RotCtldArgs := dmUtils.GetRotorRotCtldCommandLine(StrToInt(n));
   rotor.RunRotCtld  := cqrini.ReadBool('ROT'+n,'RunRotCtld',False);
   rotor.RotDevice   := cqrini.ReadString('ROT'+n,'device','');
