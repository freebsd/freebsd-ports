--- packages/graph/fpmake.pp.orig	2015-11-13 21:15:29 UTC
+++ packages/graph/fpmake.pp
@@ -26,14 +26,14 @@ begin
     P.NeedLibC:= false;  // true for headers that indirectly link to libc? OS specific?
 
     P.CPUs:=[i386,x86_64,powerpc,i8086];
-    P.OSes:=[go32v2,win32,win64,linux,freebsd,darwin,msdos];
+    P.OSes:=[go32v2,win32,win64,linux,dragonfly,freebsd,darwin,msdos];
 
-    P.Dependencies.Add('sdl',[i386,powerpc],[win32,linux,freebsd,darwin]);
+    P.Dependencies.Add('sdl',[i386,powerpc],[win32,linux,dragonfly,freebsd,darwin]);
     P.Dependencies.Add('ptc',[win32,win64,linux]);
 
     // Dependencies for ptc, due to fpcmake bug:
     P.Dependencies.Add('fcl-base',[win32,win64,linux]);
-    P.Dependencies.Add('x11',[freebsd,linux]); // ptc only depends on reebsd and linux on x11
+    P.Dependencies.Add('x11',[dragonfly,freebsd,linux]); // ptc only depends on reebsd and linux on x11
     P.Dependencies.Add('hermes',[win32,win64,linux]);
     P.Dependencies.Add('opengl',[win32,win64,linux]);
 
@@ -44,15 +44,15 @@ begin
     P.SourcePath.Add('src/go32v2',[go32v2]);
     P.SourcePath.Add('src/msdos',[msdos]);
     P.SourcePath.Add('src/win32',[win32,win64]);
-    P.SourcePath.Add('src/unix',[freebsd,linux]);  // Darwin has own.
+    P.SourcePath.Add('src/unix',[dragonfly,freebsd,linux]);  // Darwin has own.
 
     P.IncludePath.Add('src/inc');
     P.IncludePath.Add('src/go32v2',[go32v2]);
     P.IncludePath.Add('src/msdos',[msdos]);
-    P.IncludePath.Add('src/unix',[freebsd,linux]);  // Darwin has own.
+    P.IncludePath.Add('src/unix',[dragonfly,freebsd,linux]);  // Darwin has own.
     P.IncludePath.Add('src/go32v2',[go32v2]);
 
-    T:=P.Targets.AddUnit('ggigraph.pp',[linux,freebsd]);
+    T:=P.Targets.AddUnit('ggigraph.pp',[linux,dragonfly,freebsd]);
       with T.Dependencies do
         begin
           AddInclude('graphh.inc');
@@ -76,10 +76,10 @@ begin
           AddInclude('modes.inc');
           AddInclude('fills.inc');
           AddInclude('gtext.inc');
-          AddInclude('graph16.inc',[freebsd,linux]);
+          AddInclude('graph16.inc',[dragonfly,freebsd,linux]);
         end;
     // Graph unit other targets
-    T:=P.Targets.AddUnit('graph.pp',[go32v2,amiga,win32,win64,freebsd,msdos]);
+    T:=P.Targets.AddUnit('graph.pp',[go32v2,amiga,win32,win64,dragonfly,freebsd,msdos]);
       with T.Dependencies do
         begin
           AddInclude('graphh.inc');
@@ -90,12 +90,12 @@ begin
           AddInclude('modes.inc');
           AddInclude('fills.inc');
           AddInclude('gtext.inc');
-          AddInclude('graph16.inc',[freebsd,linux]);
+          AddInclude('graph16.inc',[dragonfly,freebsd,linux]);
           AddInclude('vesa.inc',[go32v2,msdos]);
           AddInclude('vesah.inc',[go32v2,msdos]);
         end;
 
-    T:=P.Targets.AddUnit('src/sdlgraph/sdlgraph.pp',[i386,powerpc],[win32,linux,freebsd,darwin]);
+    T:=P.Targets.AddUnit('src/sdlgraph/sdlgraph.pp',[i386,powerpc],[win32,linux,dragonfly,freebsd,darwin]);
       with T.Dependencies do
         begin
           AddInclude('graphh.inc');
