--- as_setup.py.orig	2014-03-05 09:41:19.000000000 +0100
+++ as_setup.py	2014-05-12 19:32:12.000000000 +0200
@@ -45,6 +45,8 @@
 import compileall
 import imp
 import pprint
+import fileinput
+import string
 import distutils.sysconfig as SC
 from subprocess import Popen, PIPE
 
@@ -516,6 +518,46 @@
       if iextr_as:
          self.Clean(to_delete=path)
 
+      # Insert FreeBSD patches here
+      file2patch = os.path.join(self.workdir, self.content, 'bibc/wscript')
+      self._print('FreeBSD patch: no libdl => modify ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = string.find(ligne, "uselib_store='SYS', lib='dl'")
+         if nl > 0:
+            ligne =ligne.replace("self.check_cc", "# self.check_cc")
+         sys.stdout.write(ligne)
+      file2patch = os.path.join(self.workdir, self.content, 'bibc/utilitai/hpalloc.c')
+      self._print('FreeBSD patch: stdlib + no mallopt => modify ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = string.find(ligne, 'ir=mallopt')
+         if nl > 0:
+            ligne =ligne.replace('ir=mallopt', '/* ir=mallopt')
+            ligne =ligne.replace(');', '); */')
+         else:
+            nl = string.find(ligne, "malloc.h")
+            if nl > 0:
+               ligne =ligne.replace("malloc.h", "stdlib.h")
+         sys.stdout.write(ligne)
+      file2patch = os.path.join(self.workdir, self.content, 'bibfor/wscript')
+      self._print('FreeBSD patch: -O2 (GCC Bug 51267) => modify ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = string.find(ligne, "-O2")
+         if nl > 0:
+            ligne =ligne.replace("-O2", "-O0")
+         sys.stdout.write(ligne)
+      file2patch = os.path.join(self.workdir, self.content, 'bibc/utilitai/mempid.c')
+      self._print('FreeBSD patch: VmData VmSize and VmPeak in /proc/%pid%/status ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = string.find(ligne, "/proc")
+         if nl > 0:
+            ligne =ligne.replace("/proc", "/compat/linux/proc")
+         sys.stdout.write(ligne)
+      # End of FreeBSD patches
+
 #-------------------------------------------------------------------------------
    def Configure(self, **kargs):
       """Configuration of the product.
