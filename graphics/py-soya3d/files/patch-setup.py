--- setup.py.orig	Tue Jul 18 15:14:24 2006
+++ setup.py	Thu Jul 27 20:21:36 2006
@@ -32,21 +32,22 @@
 INCDIR = [
 	"ode-0.5/include",
 	"/usr/include",
-	"/usr/local/include",
-	"/usr/X11R6/include",
+	"%%LOCALBASE%%/include",
+	"%%X11BASE%%/include",
 	"/usr/include/freetype2",
-	"/usr/local/include/freetype2",
+	"%%LOCALBASE%%/include/freetype2",
 	"/usr/include/cal3d",
-	"/usr/local/include/cal3d",
+	"%%LOCALBASE%%/include/SDL11",
+	"%%LOCALBASE%%/include/cal3d",
 	"/sw/include", # For Mac OS X "fink"
     "/opt/local/include", # For Mac OS X "darwin port"
 	]
 LIBDIR = [
 	"ode-0.5/lib",
 	"/usr/lib",
-	"/usr/local/lib",
+	"%%LOCALBASE%%/lib",
 	"/opt/local/lib", # For Mac OS X "darwin port"
-	"/usr/X11R6/lib",
+	"%%X11BASE%%/lib",
 	"/sw/lib/", # For Mac OS X
 	]
 
@@ -80,7 +81,7 @@
 	LIBS = ["m", "glew32", "SDL", "freetype", "cal3d", "stdc++"]
 else:
 	#LIBS = ["m", "GLEW", "GL", "GLU", "SDL", "SDL_mixer", "freetype", "cal3d", "stdc++"]
-	LIBS = ["m", "GLEW", "SDL", "freetype", "cal3d", "stdc++"]
+	LIBS = ["m", "GLEW", "SDL-1.1", "freetype", "cal3d", "stdc++"]
 
 SOYA_PYREX_SOURCES  = ["_soya.pyx", "matrix.c", "chunk.c" ]
 SOYA_C_SOURCES      = ["_soya.c"  , "matrix.c", "chunk.c" ]
@@ -133,14 +134,14 @@
 			print "ODE and OPCODE have already been compiled; if you want to recompile them do:  cd %s ; make clean" % ODE_DIR
 		else:
 			print "Building ODE and OPCODE from %s" % ODE_DIR
-			do("cd %s ; make clean" % ODE_DIR)
-			do("cd %s ; make configure" % ODE_DIR)
-			do("cd %s ; make" % ODE_DIR)
+			do("cd %s ; gmake clean" % ODE_DIR)
+			do("cd %s ; gmake configure" % ODE_DIR)
+			do("cd %s ; gmake" % ODE_DIR)
 			print "ODE and OPCODE built successfully !"
 			
 	elif SDISTING:
 		# Clean ODE, to remove configuration files and binaries
-		do("cd %s ; make clean" % ODE_DIR)
+		do("cd %s ; gmake clean" % ODE_DIR)
 	
 	
 if HAVE_PYREX:
