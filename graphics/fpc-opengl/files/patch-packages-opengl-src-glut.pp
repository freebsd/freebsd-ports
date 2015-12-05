--- packages/opengl/src/glut.pp.orig	2015-01-05 19:27:06.000000000 +0000
+++ packages/opengl/src/glut.pp
@@ -768,7 +768,7 @@ initialization
   {$ifdef darwin}
   LoadGlut('/System/Library/Frameworks/GLUT.framework/GLUT');
   {$else}
-  {$IFDEF haiku}
+  {$if defined(haiku) or defined(freebsd) or defined(dragonfly)}
   LoadGlut('libglut.so');
   {$ELSE}
   {$IFNDEF MORPHOS}
