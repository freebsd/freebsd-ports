--- packages/mad/fpmake.pp.orig	2015-11-13 21:15:29 UTC
+++ packages/mad/fpmake.pp
@@ -17,7 +17,7 @@ begin
     P.Directory:=ADirectory;
 {$endif ALLPACKAGES}
     P.Version:='3.0.0';
-    P.OSes := [linux,win32,win64,wii];
+    P.OSes := [linux,win32,win64,wii,freebsd,dragonfly];
     P.SourcePath.Add('src');
 
     T:=P.Targets.AddUnit('mad.pas');
