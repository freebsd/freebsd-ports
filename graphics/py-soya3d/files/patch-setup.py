--- setup.py.orig	2007-11-05 20:44:27.000000000 -0500
+++ setup.py	2007-11-05 20:47:14.000000000 -0500
@@ -22,6 +22,7 @@
 
 # Modify the following if needed :
 USE_OPENAL = 1     # use OpenAL
+HAVE_PYREX = 0
 #USE_OPENAL = 0
 
 # Modify the following if needed :
@@ -76,12 +77,6 @@
 SDISTING = ("sdist" in sys.argv[1:]) and not ("--help" in sys.argv[1:])
 
 
-try:
-	from Pyrex.Distutils import build_ext
-	HAVE_PYREX = 1
-except:
-	HAVE_PYREX = 0
-
 HERE = os.path.dirname(sys.argv[0])
 #ODE_DIR = os.path.join(HERE, "ode-0.5")
 DEFINES = []
@@ -129,6 +124,7 @@
 		DEFINES.append(('SOYA_MACOSX',1))
 	else:
 		LIBS.append("openal")
+		LIBS.append("alut")
 
 
 if "darwin" in sys.platform:
