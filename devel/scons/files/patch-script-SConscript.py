--- engine/SCons/Script/SConscript.py.orig	Wed Feb 16 03:12:11 2005
+++ engine/SCons/Script/SConscript.py	Thu Mar 17 14:07:00 2005
@@ -55,6 +55,16 @@
 import types
 import UserList
 
+# The following variables used to live in this module.  Some
+# SConscript files out there may have referred to them directly as
+# SCons.Script.SConscript.*.  This is now supported by some special
+# handling towards the bottom of the SConscript.__init__.py module.
+#Arguments = {}
+#ArgList = []
+#BuildTargets = TargetList()
+#CommandLineTargets = []
+#DefaultTargets = []
+
 launch_dir = os.path.abspath(os.curdir)
 
 GlobalDict = None
@@ -230,7 +240,9 @@
                 # Repository directory.  Like above, we do this
                 # directly.
                 fs.chdir(frame.prev_dir, change_os_dir=0)
-                os.chdir(frame.prev_dir.rdir().get_abspath())
+                rdir = frame.prev_dir.rdir()
+                rdir._create()  # Make sure there's a directory there.
+                os.chdir(rdir.get_abspath())
 
             results.append(frame.retval)
 
