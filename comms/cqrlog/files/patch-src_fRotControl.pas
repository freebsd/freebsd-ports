--- src/fRotControl.pas.orig	2021-01-16 14:03:35 UTC
+++ src/fRotControl.pas
@@ -285,7 +285,7 @@ begin
   if not TryStrToInt(cqrini.ReadString('ROT'+n,'poll','500'),poll) then
     poll := 500;
 
-  rotor.RotCtldPath := cqrini.ReadString('ROT','RotCtldPath','/usr/bin/rotctld');
+  rotor.RotCtldPath := cqrini.ReadString('ROT','RotCtldPath','%%LOCALBASE%%/bin/rotctld');
   rotor.RotCtldArgs := dmUtils.GetRotorRotCtldCommandLine(StrToInt(n));
   rotor.RunRotCtld  := cqrini.ReadBool('ROT'+n,'RunRotCtld',False);
   rotor.RotDevice   := cqrini.ReadString('ROT'+n,'device','');
