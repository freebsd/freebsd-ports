--- as_setup.py.orig	2010-02-09 10:04:57.000000000 +0100
+++ as_setup.py	2010-02-20 15:49:39.000000000 +0100
@@ -47,6 +47,8 @@
 import imp
 import shutil
 import pprint
+import fileinput
+import string
 from types import StringTypes
 EnumTypes=(list, tuple)
 
@@ -449,6 +451,17 @@
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
@@ -1302,7 +1315,10 @@
       from socket import gethostname, gethostbyaddr
       if host==None:
          host = gethostname()
-      fqn, alias, ip = gethostbyaddr(host)
+      try:
+         fqn, alias, ip = gethostbyaddr(host)
+      except:
+         fqn='put-your-host-name.here'
       if fqn.find('localhost')>-1:
          alias=[a for a in alias if a.find('localhost')<0]
          if len(alias)>0:
