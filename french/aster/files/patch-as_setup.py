--- as_setup.py.orig	2014-03-05 09:41:19.000000000 +0100
+++ as_setup.py	2014-05-24 15:16:48.000000000 +0200
@@ -45,6 +45,8 @@
 import compileall
 import imp
 import pprint
+import fileinput
+import string
 import distutils.sysconfig as SC
 from subprocess import Popen, PIPE
 
@@ -408,6 +410,7 @@
             archive filename !),
          extract_as : rename content.
       """
+      from as_setup import (SYSTEM)
       self._print(self._fmt_title % _('Extraction'))
       if kargs.get('external')<>None:
          self._call_external(**kargs)
@@ -516,6 +519,47 @@
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
+      file2patch = os.path.join(self.workdir, self.content, 'bibc/utilitai/mempid.c')
+      self._print('FreeBSD patch: VmData VmSize and VmPeak in /proc/%pid%/status ' + file2patch)
+      system=SYSTEM({ 'verbose' : True, 'debug' : False },
+         **{'maxcmdlen' : 2**31, 'log' : self})
+      iret, out = system.local_shell('cd ' + os.path.join(self.workdir, self.content) + '&& /usr/bin/patch -p0 < ' + '%%FILESDIR%%' + '/bibc_utilitai_mempid.c.diff')
+      # End of FreeBSD patches
+
 #-------------------------------------------------------------------------------
    def Configure(self, **kargs):
       """Configuration of the product.
