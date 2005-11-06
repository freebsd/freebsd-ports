--- setup.py	Fri Aug 19 16:05:49 2005
+++ setup.py	Sat Nov  5 13:13:31 2005
@@ -25,19 +25,19 @@
 INCDIR = [
   "ode-0.5/include",
   "/usr/include",
-  "/usr/local/include",
-  "/usr/X11R6/include",
+  "%%LOCALBASE%%/include",
+  "%%X11BASE%%/include",
   "/usr/include/freetype2",
-  "/usr/local/include/freetype2",
+  "%%LOCALBASE%%/include/freetype2",
   "/usr/include/cal3d",
-  "/usr/local/include/cal3d",
+  "%%LOCALBASE%%/include/cal3d",
   "/sw/include", # For Mac OS X
   ]
 LIBDIR = [
   "ode-0.5/lib",
   "/usr/lib",
-  "/usr/local/lib",
-  "/usr/X11R6/lib",
+  "%%LOCALBASE%%/lib",
+  "%%X11BASE%%/lib",
   "/sw/lib/", # For Mac OS X
   ]
 
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
