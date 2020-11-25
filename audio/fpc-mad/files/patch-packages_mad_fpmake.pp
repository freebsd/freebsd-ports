--- packages/mad/fpmake.pp	2017-09-02 11:48:24.000000000 -0500
+++ packages/mad/fpmake.pp	2017-12-12 12:22:21.182111000 -0500
@@ -17,7 +17,7 @@
     P.Directory:=ADirectory;
 {$endif ALLPACKAGES}
     P.Version:='3.2.0';
-    P.OSes := [linux,win32,win64,wii];
+    P.OSes := [linux,win32,win64,wii,dragonfly,freebsd];
     P.SourcePath.Add('src');
 
     T:=P.Targets.AddUnit('mad.pas');
