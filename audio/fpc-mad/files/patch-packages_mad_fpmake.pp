--- packages/mad/fpmake.pp.orig	2015-08-29 16:37:05 UTC
+++ packages/mad/fpmake.pp
@@ -17,7 +17,7 @@ begin
     P.Directory:=ADirectory;
 {$endif ALLPACKAGES}
     P.Version:='3.0.0';
-    P.OSes := [linux,win32,win64,wii];
+    P.OSes := [linux,win32,win64,wii,freebsd,dragonfly];
     P.SourcePath.Add('src');
 
     T:=P.Targets.AddUnit('mad.pas');
