--- packages/newt/fpmake.pp.orig	2015-01-05 19:27:06.000000000 +0000
+++ packages/newt/fpmake.pp
@@ -18,7 +18,7 @@ begin
 {$endif ALLPACKAGES}
     P.Version:='3.0.1';
     P.SourcePath.Add('src');
-    P.OSes:=[Linux];
+    P.OSes:=[Linux,dragonfly,freebsd];
 
     T:=P.Targets.AddUnit('newt.pp');
 
