--- packages/opengl/src/glut.pp	2020-10-04 23:20:00.147154000 -0500
+++ packages/opengl/src/glut.pp	2020-10-04 23:20:56.679328000 -0500
@@ -765,7 +765,7 @@
   LoadGlut('glut.dll');
   {$elseif defined(darwin)}
   LoadGlut('/System/Library/Frameworks/GLUT.framework/GLUT');
-  {$elseif defined(haiku) or defined(OpenBSD)}
+  {$elseif defined(haiku) or defined(OpenBSD) or defined(freebsd) or defined(dragonfly)}
   LoadGlut('libglut.so');
   {$elseif defined(MORPHOS)}
   {nothing}
