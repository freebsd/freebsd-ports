--- setup.py	2009-04-22 10:00:23.000000000 -0500
+++ setup.py	2009-04-22 10:03:23.000000000 -0500
@@ -21,6 +21,7 @@
 
 # Modify the following if needed :
 USE_OPENAL = 1     # use OpenAL
+HAVE_PYREX = 0
 #USE_OPENAL = 0
 
 # Modify the following if needed :
@@ -32,7 +33,7 @@
 INCDIR = [
 	#"ode-0.5/include",
 	"/usr/include",
-	"/usr/local/include",
+	"%%LOCALBASE%%/include",
 	"/usr/X11R6/include",
 	"/usr/X11/include",
 	"/usr/include/freetype2",
@@ -48,7 +49,7 @@
 LIBDIR = [
 	#"ode-0.5/lib",
 	"/usr/lib",
-	"/usr/local/lib",
+	"%%LOCALBASE%%/lib",
 	"/opt/local/lib", # For Mac OS X "darwin port"
 	"/usr/X11R6/lib",
 	"/usr/X11/lib",
@@ -79,11 +80,6 @@
 SDISTING = ("sdist" in sys.argv[1:]) and not ("--help" in sys.argv[1:])
 
 MACOSX_DEPLOYMENT_TARGET  = os.getenv('MACOSX_DEPLOYMENT_TARGET')
-try:
-	from Pyrex.Distutils import build_ext
-	HAVE_PYREX = 1
-except:
-	HAVE_PYREX = 0
 
 # Only enable Pyrex compilation for SVN sources
 if not os.path.exists(os.path.join(os.path.dirname(__file__), ".svn")):
@@ -159,6 +155,7 @@
 		DEFINES.append(('SOYA_MACOSX',1))
 	else:
 		LIBS.append("openal")
+		LIBS.append("alut")
 
 
 if "darwin" in sys.platform:
