--- packages/proj4/fpmake.pp.orig	2015-01-05 19:27:06.000000000 +0000
+++ packages/proj4/fpmake.pp
@@ -19,7 +19,7 @@ begin
     P.Version:='3.0.1';
     P.SourcePath.Add('src');
     P.IncludePath.Add('src');
-    P.OSes := [linux];
+    P.OSes := [linux,dragonfly,freebsd];
 
   T:=P.Targets.AddUnit('proj.pas');
   with T.Dependencies do
