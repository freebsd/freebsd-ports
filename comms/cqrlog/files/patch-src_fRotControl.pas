--- src/fRotControl.pas.orig	2014-06-30 23:40:26.000000000 -0700
+++ src/fRotControl.pas	2014-06-30 23:40:33.000000000 -0700
@@ -130,7 +130,7 @@
     rotor.RotId := 1
   else
     rotor.RotId := id;
-  rotor.RotCtldPath := cqrini.ReadString('ROT','RigCtldPath','/usr/bin/rotctld');
+  rotor.RotCtldPath := cqrini.ReadString('ROT','RigCtldPath','%%LOCALBASE%%/bin/rotctld');
   rotor.RotCtldArgs := dmUtils.GetRotorRotCtldCommandLine(StrToInt(n));
   rotor.RunRotCtld  := cqrini.ReadBool('ROT'+n,'RunRotCtld',False);
   rotor.RotDevice   := cqrini.ReadString('ROT'+n,'device','');
