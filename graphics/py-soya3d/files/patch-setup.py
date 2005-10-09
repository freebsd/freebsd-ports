--- setup.py.old	Wed Oct  5 00:05:48 2005
+++ setup.py	Wed Oct  5 02:47:23 2005
@@ -63,10 +63,10 @@
 from config import *
 
 if sys.platform[:3] == "win":
-  LIBS = ["m", "glew32", "SDL", "SDL_mixer", "freetype", "cal3d", "stdc++"]
+  LIBS = ["m", "glew32", "SDL-1.1", "SDL_mixer", "freetype", "cal3d", "stdc++"]
 else:
   #LIBS = ["m", "GLEW", "GL", "GLU", "SDL", "SDL_mixer", "freetype", "cal3d", "stdc++"]
-  LIBS = ["m", "GLEW", "SDL", "freetype", "cal3d", "stdc++"]
+  LIBS = ["m", "GLEW", "SDL-1.1", "freetype", "cal3d", "stdc++"]
 
 SOYA_PYREX_SOURCES  = ["_soya.pyx", "matrix.c", "chunk.c" ]
 SOYA_C_SOURCES      = ["_soya.c"  , "matrix.c", "chunk.c" ]
@@ -97,14 +97,14 @@
       print "ODE and OPCODE have already been compiled; if you want to recompile them do:  cd %s ; make clean" % ODE_DIR
     else:
       print "Building ODE and OPCODE from %s" % ODE_DIR
-      do("cd %s ; make clean" % ODE_DIR)
-      do("cd %s ; make configure" % ODE_DIR)
-      do("cd %s ; make" % ODE_DIR)
+      do("cd %s ; gmake clean" % ODE_DIR)
+      do("cd %s ; gmake configure" % ODE_DIR)
+      do("cd %s ; gmake" % ODE_DIR)
       print "ODE and OPCODE built successfully !"
       
   elif "sdist" in sys.argv:
     # Clean ODE, to remove configuration files and binaries
-    do("cd %s ; make clean" % ODE_DIR)
+    do("cd %s ; gmake clean" % ODE_DIR)
   
   
 if HAVE_PYREX:
