--- as_setup.py.orig	2016-09-07 08:44:22 UTC
+++ as_setup.py
@@ -45,6 +45,8 @@ import tarfile
 import compileall
 import imp
 import pprint
+import fileinput
+import string
 import distutils.sysconfig as SC
 from subprocess import Popen, PIPE
 
@@ -410,6 +412,7 @@ class SETUP:
             archive filename !),
          extract_as : rename content.
       """
+      from as_setup import (SYSTEM)
       self._print(self._fmt_title % _('Extraction'))
       if kargs.get('external')<>None:
          self._call_external(**kargs)
@@ -518,6 +521,60 @@ class SETUP:
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
+      file2patch = os.path.join(self.workdir, self.content, 'bibcxx/wscript')
+      self._print('FreeBSD patch: explicit link with libc++ required since Gcc 4.9 => modify ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = string.find(ligne, "uselib_store='CXX', lib='stdc++'")
+         if nl > 0:
+            ligne =ligne.replace("lib='stdc++'", "lib='c++ stdc++'")
+         sys.stdout.write(ligne)
+      file2patch = os.path.join(self.workdir, self.content, 'waftools/scotch.py')
+      self._print('FreeBSD patch: int64_t missing => modify ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = string.find(ligne, 'include "scotch.h"')
+         if nl > 0:
+            sys.stdout.write("#include <sys/types.h>\n")
+         nl = 0
+         nl = string.find(ligne, "stdio.h stdlib.h scotch.h")
+         if nl > 0:
+            ligne =ligne.replace("stdlib.h", "stdlib.h sys/types.h")
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
+      system=SYSTEM({ 'verbose' : True, 'debug' : False },
+         **{'maxcmdlen' : 2**31, 'log' : self})
+      file2patch = os.path.join(self.workdir, self.content, 'waftools/med.py')
+      self._print('FreeBSD patch: only hdf5-18 is supported ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = string.find(ligne, "opts.hdf5_libs = 'hdf5'")
+         if nl > 0:
+            ligne =ligne.replace("'hdf5'", "'hdf5-18'")
+         sys.stdout.write(ligne)
+      # End of FreeBSD patches
+
 #-------------------------------------------------------------------------------
    def Configure(self, **kargs):
       """Configuration of the product.
