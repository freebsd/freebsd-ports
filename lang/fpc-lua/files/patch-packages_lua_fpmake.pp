--- packages/lua/fpmake.pp.orig	2015-01-05 19:27:06.000000000 +0000
+++ packages/lua/fpmake.pp
@@ -19,7 +19,7 @@ begin
     P.Version:='3.0.1';
     P.SourcePath.Add('src');
 //    P.Dependencies.Add('x11');
-    P.OSes := [linux,win32];
+    P.OSes := [linux,win32,dragonfly,freebsd];
 
     T:=P.Targets.AddUnit('lauxlib.pas');
       with T.Dependencies do
