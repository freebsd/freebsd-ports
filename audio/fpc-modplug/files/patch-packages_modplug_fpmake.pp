--- packages/modplug/fpmake.pp.orig	2015-11-13 21:15:29 UTC
+++ packages/modplug/fpmake.pp
@@ -17,7 +17,7 @@ begin
     P.Directory:=ADirectory;
 {$endif ALLPACKAGES}
     P.Version:='3.0.0';
-    P.OSes := [linux];
+    P.OSes := [linux,dragonfly,freebsd];
     P.SourcePath.Add('src');
 
     T:=P.Targets.AddUnit('modplug.pas');
