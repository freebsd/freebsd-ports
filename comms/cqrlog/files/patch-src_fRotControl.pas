--- src/fRotControl.pas.orig	2016-04-20 16:06:15 UTC
+++ src/fRotControl.pas
@@ -149,7 +149,7 @@ begin
   if not TryStrToInt(cqrini.ReadString('ROT'+n,'poll','500'),poll) then
     poll := 500;
 
-  rotor.RotCtldPath := cqrini.ReadString('ROT','RigCtldPath','/usr/bin/rotctld');
+  rotor.RotCtldPath := cqrini.ReadString('ROT','RigCtldPath','%%LOCALBASE%%/bin/rotctld');
   rotor.RotCtldArgs := dmUtils.GetRotorRotCtldCommandLine(StrToInt(n));
   rotor.RunRotCtld  := cqrini.ReadBool('ROT'+n,'RunRotCtld',False);
   rotor.RotDevice   := cqrini.ReadString('ROT'+n,'device','');
