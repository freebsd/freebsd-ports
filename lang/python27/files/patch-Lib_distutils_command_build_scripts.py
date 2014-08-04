# Description: A non-invasive partial backport of the Python3 distutils behaviour.
# This allows Python's scripts to be properly suffixed (similar to Python 3.x) on
# installation.
# Submitted by: mva

--- Lib/distutils/command/build_scripts.py.orig	2014-07-26 11:52:20.000000000 +0200
+++ Lib/distutils/command/build_scripts.py	2014-07-26 11:52:56.000000000 +0200
@@ -126,6 +126,9 @@
                                  file, oldmode, newmode)
                         os.chmod(file, newmode)
 
+        # XXX should we modify self.outfiles?
+        return outfiles
+
     # copy_scripts ()
 
 # class build_scripts
