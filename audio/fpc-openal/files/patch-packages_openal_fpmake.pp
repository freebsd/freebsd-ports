--- packages/openal/fpmake.pp.orig	2015-01-05 19:27:06.000000000 +0000
+++ packages/openal/fpmake.pp
@@ -19,9 +19,9 @@ begin
 {$endif ALLPACKAGES}
     P.Version:='3.0.1';
     if Defaults.CPU = i386 then
-      P.OSes := [linux,win32,darwin]
+      P.OSes := [linux,win32,darwin,dragonfly,freebsd]
     else
-      P.OSes := [linux,win32];
+      P.OSes := [linux,win32,dragonfly,freebsd];
     P.SourcePath.Add('src');
     P.IncludePath.Add('src');
 
