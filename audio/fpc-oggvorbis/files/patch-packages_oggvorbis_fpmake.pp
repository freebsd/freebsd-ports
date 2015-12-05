--- packages/oggvorbis/fpmake.pp.orig	2015-01-05 19:27:06.000000000 +0000
+++ packages/oggvorbis/fpmake.pp
@@ -19,7 +19,7 @@ begin
 {$endif ALLPACKAGES}
     P.Version:='3.0.1';
     P.SourcePath.Add('src');
-    P.OSes := [linux,win32,wince];
+    P.OSes := [linux,win32,wince,dragonfly,freebsd];
 //    P.Dependencies.Add('x11');
 
    T:=P.Targets.AddUnit('ogg.pas');
