--- packages/graph/fpmake.pp	2021-05-13 06:42:31.000000000 -0500
+++ packages/graph/fpmake.pp	2024-01-05 10:37:36.481679000 -0500
@@ -29,13 +29,13 @@
     P.OSes:=[go32v2,win32,win64,linux,freebsd,darwin,msdos];
 
     P.Dependencies.Add('sdl',[i386,powerpc],[win32,linux,freebsd,darwin]);
-    P.Dependencies.Add('ptc',[win32,win64,linux]);
+    P.Dependencies.Add('ptc',[win32,win64,linux,freebsd]);
 
     // Dependencies for ptc, due to fpcmake bug:
-    P.Dependencies.Add('fcl-base',[win32,win64,linux]);
+    P.Dependencies.Add('fcl-base',[win32,win64,linux,freebsd]);
     P.Dependencies.Add('x11',[freebsd,linux]); // ptc only depends on reebsd and linux on x11
-    P.Dependencies.Add('hermes',[win32,win64,linux]);
-    P.Dependencies.Add('opengl',[win32,win64,linux]);
+    P.Dependencies.Add('hermes',[win32,win64,freebsd,linux]);
+    P.Dependencies.Add('opengl',[win32,win64,freebsd,linux]);
 
     P.SourcePath.Add('src');
     P.SourcePath.Add('src/ptcgraph');
@@ -52,7 +52,7 @@
     P.IncludePath.Add('src/unix',[freebsd,linux]);  // Darwin has own.
     P.IncludePath.Add('src/go32v2',[go32v2]);
 
-    T:=P.Targets.AddUnit('ggigraph.pp',[linux,freebsd]);
+    T:=P.Targets.AddUnit('ggigraph.pp',[freebsd,linux]);
       with T.Dependencies do
         begin
           AddInclude('graphh.inc');
@@ -117,7 +117,7 @@
         begin
           AddUnit('graph');
         end;
-    T:=P.Targets.AddUnit('ptcgraph.pp',[win32,win64,linux]);
+    T:=P.Targets.AddUnit('ptcgraph.pp',[win32,win64,freebsd,linux]);
       with T.Dependencies do
         begin
           AddInclude('graphh.inc');
@@ -129,12 +129,12 @@
           AddInclude('fills.inc');
           AddInclude('gtext.inc');
         end;
-    T:=P.Targets.AddUnit('ptccrt.pp',[win32,win64,linux]);
+    T:=P.Targets.AddUnit('ptccrt.pp',[win32,win64,freebsd,linux]);
       with T.Dependencies do
         begin
           AddUnit('ptcgraph');
         end;
-    T:=P.Targets.AddUnit('ptcmouse.pp',[win32,win64,linux]);
+    T:=P.Targets.AddUnit('ptcmouse.pp',[win32,win64,freebsd,linux]);
       with T.Dependencies do
         begin
           AddUnit('ptcgraph');
