--- packages/rexx/fpmake.pp.orig	2015-01-05 19:27:06.000000000 +0000
+++ packages/rexx/fpmake.pp
@@ -18,7 +18,7 @@ begin
 {$endif ALLPACKAGES}
     P.Version:='3.0.1';
     P.SourcePath.Add('src');
-    P.Oses:=[emx,os2];
+    P.Oses:=[emx,os2,dragonfly,freebsd];
     p.Targets.AddUnit('rexxsaa.pp');
 
     P.Sources.AddSrc('readme.txt');
