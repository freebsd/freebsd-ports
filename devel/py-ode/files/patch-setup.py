--- setup.py.orig	Thu Jul  7 15:36:03 2005
+++ setup.py	Fri Jan 26 22:54:51 2007
@@ -150,22 +150,11 @@
 script so that it points to the actual location of the ODE directory."""%ODE_BASE
     sys.exit()
 
-config = readODEConfig()
-
 generate('ode_trimesh.c', True)
 generate('ode_notrimesh.c', False)
 
-try:
-    wrap_trimesh = TRIMESH_SUPPORT_OVERRIDE
-except NameError, e:
-    wrap_trimesh = config.get('OPCODE_DIRECTORY', '')
-
-if (wrap_trimesh):
-    print "Installing with trimesh support."
-    install = 'ode_trimesh.c'
-else:
-    print "Installing without trimesh support."
-    install = 'ode_notrimesh.c'
+print "Installing without trimesh support."
+install = 'ode_notrimesh.c'
 
 # Compile the module
 setup(name = "PyODE",
