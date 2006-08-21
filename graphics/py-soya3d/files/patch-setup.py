--- setup.py	Mon Aug 21 00:22:53 2006
+++ setup.py	Mon Aug 21 00:24:52 2006
@@ -37,6 +37,7 @@
 	"/usr/include/freetype2",
 	"/usr/local/include/freetype2",
 	"/usr/include/cal3d",
+	"/usr/local/include/SDL11",
 	"/usr/local/include/cal3d",
 	"/sw/include", # For Mac OS X "fink"
     "/opt/local/include", # For Mac OS X "darwin port"
@@ -80,7 +81,7 @@
 	LIBS = ["m", "glew32", "SDL", "freetype", "cal3d", "stdc++"]
 else:
 	#LIBS = ["m", "GLEW", "GL", "GLU", "SDL", "SDL_mixer", "freetype", "cal3d", "stdc++"]
-	LIBS = ["m", "GLEW", "SDL", "freetype", "cal3d", "stdc++"]
+	LIBS = ["m", "GLEW", "SDL-1.1", "freetype", "cal3d", "stdc++"]
 
 SOYA_PYREX_SOURCES  = ["_soya.pyx", "matrix.c", "chunk.c" ]
 SOYA_C_SOURCES      = ["_soya.c"  , "matrix.c", "chunk.c" ]
@@ -99,6 +100,7 @@
 	if USE_OPENAL:
 		print "Sound support (with OpenAL) enabled..."
 		LIBS.append("openal")
+		LIBS.append("alut")
 		CONFIG_PXD_FILE.write("""include "sound/al.pxd"\n""")
 		CONFIG_PYX_FILE.write("""include "sound/sound.pyx"\n""")
 	else:
@@ -133,14 +135,14 @@
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
