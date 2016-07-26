--- packages/openal/fpmake.pp.orig	2015-11-13 21:15:29 UTC
+++ packages/openal/fpmake.pp
@@ -19,9 +19,9 @@ begin
 {$endif ALLPACKAGES}
     P.Version:='3.0.0';
     if Defaults.CPU = i386 then
-      P.OSes := [linux,win32,darwin]
+      P.OSes := [linux,win32,darwin,dragonfly,freebsd]
     else
-      P.OSes := [linux,win32];
+      P.OSes := [linux,win32,dragonfly,freebsd];
     P.SourcePath.Add('src');
     P.IncludePath.Add('src');
 
