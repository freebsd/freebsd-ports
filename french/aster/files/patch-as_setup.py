--- as_setup.py.orig	2010-07-07 18:18:13.000000000 +0200
+++ as_setup.py	2010-08-12 19:01:09.000000000 +0200
@@ -46,6 +46,8 @@
 import compileall
 import imp
 import pprint
+import fileinput
+import string
 import distutils.sysconfig as SC
 from types import StringTypes
 EnumTypes=(list, tuple)
@@ -472,6 +474,17 @@
       if iextr_as:
          self.Clean(to_delete=path)
 
+      # Insert FreeBSD patches here
+      file2patch = os.path.join(self.installdir, self.content, 'bibc/utilitai/mempid.c')
+      self._print('different /proc/pid/status => change ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = string.find(ligne, 'ifdef _POSIX')
+         if nl > 0:
+            ligne =ligne.replace('ifdef _POSIX', 'ifndef __FreeBSD__')
+         sys.stdout.write(ligne)
+      # End of FreeBSD patches
+
 #-------------------------------------------------------------------------------
    def Configure(self, **kargs):
       """Configuration of the product.
