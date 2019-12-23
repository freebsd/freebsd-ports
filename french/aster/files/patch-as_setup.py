--- as_setup.py.orig	2019-10-01 12:45:34 UTC
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
       if kargs.get('external')!=None:
          self._call_external(**kargs)
@@ -518,6 +521,78 @@ class SETUP:
       if iextr_as:
          self.Clean(to_delete=path)
 
+      # Insert FreeBSD patches here
+      file2patch = os.path.join(self.workdir, self.content, 'bibc/wscript')
+      self._print('FreeBSD patch: no libdl => modify ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = ligne.find("uselib_store='SYS', lib='dl'")
+         if nl > 0:
+            ligne =ligne.replace("self.check_cc", "# self.check_cc")
+         sys.stdout.write(ligne)
+ #     file2patch = os.path.join(self.workdir, self.content, 'bibcxx/wscript')
+ #     self._print('FreeBSD patch: explicit link with libc++ required since Gcc 4.9 => modify ' + file2patch)
+ #     for ligne in fileinput.input(file2patch, inplace=1):
+ #        nl = 0
+ #        nl = ligne.find("uselib_store='CXX', lib='stdc++'")
+ #        if nl > 0:
+ #           ligne =ligne.replace("lib='stdc++'", "lib='c++ stdc++'")
+ #        sys.stdout.write(ligne)
+      file2patch = os.path.join(self.workdir, self.content, 'waftools/scotch.py')
+      self._print('FreeBSD patch: int64_t missing => modify ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = ligne.find('include "scotch.h"')
+         if nl > 0:
+            sys.stdout.write("#include <sys/types.h>\n")
+         nl = 0
+         nl = ligne.find("stdio.h stdlib.h scotch.h")
+         if nl > 0:
+            ligne =ligne.replace("stdlib.h", "stdlib.h sys/types.h")
+         sys.stdout.write(ligne)
+      file2patch = os.path.join(self.workdir, self.content, 'bibc/utilitai/hpalloc.c')
+      self._print('FreeBSD patch: stdlib + no mallopt => modify ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = ligne.find('ir=mallopt')
+         if nl > 0:
+            ligne =ligne.replace('ir=mallopt', '/* ir=mallopt')
+            ligne =ligne.replace(');', '); */')
+         else:
+            nl = ligne.find("malloc.h")
+            if nl > 0:
+               ligne =ligne.replace("malloc.h", "stdlib.h")
+         sys.stdout.write(ligne)
+      system=SYSTEM({ 'verbose' : True, 'debug' : False },
+         **{'maxcmdlen' : 2**31, 'log' : self})
+      for f2p in ('waf', 'waf.main', 'waf_variant', 'waf_std', 'waf_mpi', 'bibpyt/Macro/macr_ecre_calc_ops.py'):
+         file2patch = os.path.join(self.workdir, self.content, f2p)
+         self._print('FreeBSD patch: /bin/bash => modify ' + file2patch)
+         for ligne in fileinput.input(file2patch, inplace=1):
+            nl = 0
+            nl = ligne.find("/bin/bash")
+            if nl > 0:
+               ligne =ligne.replace("/bin/bash", " %%LOCALBASE%%/bin/bash")
+            sys.stdout.write(ligne)
+         for ligne in fileinput.input(file2patch, inplace=1):
+            nl = 0
+            nl = ligne.find("getopt ")
+            if nl > 0:
+               ligne =ligne.replace("getopt ", "getopts ")
+            sys.stdout.write(ligne)
+      self._print('FreeBSD patches: waf.engine and data/post_install in %s' % os.path.join(self.workdir, self.content))
+      os.system('cd ' + os.path.join(self.workdir, self.content) + ' && patch -p0 < /usr/ports/french/aster/work/post_patches/post-patch-waf.engine')
+      os.system('cd ' + os.path.join(self.workdir, self.content) + ' && patch -p0 < /usr/ports/french/aster/work/post_patches/post-patch-data__post_install')
+      file2patch = os.path.join(self.workdir, self.content, 'waftools/mathematics.py')
+      self._print('FreeBSD patch: nproc => gnproc ' + file2patch)
+      for ligne in fileinput.input(file2patch, inplace=1):
+         nl = 0
+         nl = ligne.find("'nproc'")
+         if nl > 0:
+            ligne =ligne.replace("'nproc'", "'gnproc'")
+         sys.stdout.write(ligne)
+      # End of FreeBSD patches
+
 #-------------------------------------------------------------------------------
    def Configure(self, **kargs):
       """Configuration of the product.
@@ -1454,7 +1529,7 @@ class SYSTEM:
       if type(profile) is str:
          ftmp = osp.join(self._tmpdir, 'temp.opt_env')
          open(ftmp, 'w').write(profile)
-         os.chmod(ftmp, 755)
+         os.chmod(ftmp, 0o755)
          profile = ftmp
 
       if not osp.isfile(profile):
