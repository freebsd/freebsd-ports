--- packages/oggvorbis/fpmake.pp.orig	2015-11-13 21:15:29 UTC
+++ packages/oggvorbis/fpmake.pp
@@ -19,7 +19,7 @@ begin
 {$endif ALLPACKAGES}
     P.Version:='3.0.0';
     P.SourcePath.Add('src');
-    P.OSes := [linux,win32,wince];
+    P.OSes := [linux,win32,wince,dragonfly,freebsd];
 //    P.Dependencies.Add('x11');
 
    T:=P.Targets.AddUnit('ogg.pas');
