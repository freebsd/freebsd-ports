--- packages/libvlc/fpmake.pp	2023-10-28 00:57:22.224953000 -0500
+++ packages/libvlc/fpmake.pp	2023-10-28 00:57:38.346447000 -0500
@@ -23,8 +23,8 @@
     P.HomepageURL := 'www.freepascal.org';
     P.Email := 'michael@freepascal.org';
     P.Description := 'VLC library (version 2 or higher) interface and component.';
-    T:=P.Targets.AddUnit('src/libvlc.pp',[linux,win32,win64]);
-    T:=P.Targets.AddUnit('src/vlc.pp',[linux,win32,win64]);
+    T:=P.Targets.AddUnit('src/libvlc.pp',[freebsd,linux,win32,win64]);
+    T:=P.Targets.AddUnit('src/vlc.pp',[freebsd,linux,win32,win64]);
     with T.Dependencies do
       begin
       AddUnit('libvlc');
