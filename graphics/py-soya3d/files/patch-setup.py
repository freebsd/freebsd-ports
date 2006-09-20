--- setup.py	Mon Aug 21 00:22:53 2006
+++ setup.py	Mon Aug 21 00:24:52 2006
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
