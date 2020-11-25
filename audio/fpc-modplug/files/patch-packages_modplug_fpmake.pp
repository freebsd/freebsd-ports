--- packages/modplug/fpmake.pp	2017-09-02 11:48:24.000000000 -0500
+++ packages/modplug/fpmake.pp	2017-12-12 12:24:14.440128000 -0500
@@ -17,7 +17,7 @@
     P.Directory:=ADirectory;
 {$endif ALLPACKAGES}
     P.Version:='3.2.0';
-    P.OSes := [linux];
+    P.OSes := [linux,dragonfly,freebsd];
     P.SourcePath.Add('src');
 
     T:=P.Targets.AddUnit('modplug.pas');
