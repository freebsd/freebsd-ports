--- packages/opengl/src/glut.pp	2013-03-23 01:19:14.000000000 -0500
+++ packages/opengl/src/glut.pp	2013-03-23 01:22:47.000000000 -0500
@@ -765,13 +765,13 @@
   {$ifdef darwin}
   LoadGlut('/System/Library/Frameworks/GLUT.framework/GLUT');
   {$else}
-  {$IFDEF haiku}
+  {$if defined(haiku) or defined(freebsd)}
   LoadGlut('libglut.so');
-  {$ELSE}
+  {$else}
   {$IFNDEF MORPHOS}
   LoadGlut('libglut.so.3');
   {$ENDIF}
-  {$ENDIF}
+  {$endif}
   {$endif}
   {$ENDIF}
 
