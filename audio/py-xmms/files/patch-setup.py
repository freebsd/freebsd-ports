--- setup.py.orig	Sun Nov  9 12:15:24 2003
+++ setup.py	Mon Nov 10 20:55:24 2003
@@ -20,7 +20,7 @@
 # Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 # MA 02111-1307, USA.
 
-import os, string, sys, distutils.dist
+import os, string, sys, re, distutils.dist
 from distutils.core import setup, Extension
 
 # Note:
@@ -30,9 +30,21 @@
 #   run the Distutils from Python 2.1, you will get License: UNKNOWN. This
 #   problem does not appear with the versions included in Python 2.2 and 2.3.
 
+def patch4gcc3(fname):
+    instr = 0
+    cont = open(fname).readlines()
+    of = open(fname, 'w')
+    for l in cont:
+        instr = (instr+len(re.findall(r'(^")|([^\\]")', l))) % 2
+        print >>of, l[:-1] + ((not l.startswith('/*') and instr) and "\\n\\" or "")
+if 'patch' in sys.argv:
+    patch4gcc3('src/_xmmscontrolmodule.c')
+    raise SystemExit
+
 PACKAGE = "pyxmms"
 VERSION = "2.00"
-GLIB_CONFIG = "glib-config"
+GLIB_CONFIG = os.environ['GLIB_CONFIG']
+XMMS_CONFIG = os.environ['XMMS_CONFIG']
 
 
 def get_glib_config():
@@ -70,13 +82,16 @@
 def setup_args():
     """Craft appropriate arguments for distutils.setup."""
     (glib_include_dirs, glib_compile_args, glib_link_args) = get_glib_config()
+
+    XMMSINCDIR = re.findall('-I([^ ]+)', os.popen(XMMS_CONFIG+" --cflags").read())
+    XMMSLIBDIR = re.findall('-L([^ ]+)', os.popen(XMMS_CONFIG+" --libs").read())
     
     # Modules built whatever the version of the running Python
     ext_modules = [Extension("xmms._xmmscontrol",
                              ["src/_xmmscontrolmodule.c"],
-                             include_dirs=glib_include_dirs,
+                             include_dirs=glib_include_dirs+XMMSINCDIR,
                              extra_compile_args=glib_compile_args,
-                             libraries=["xmms"],
+                             libraries=["xmms"], library_dirs=XMMSLIBDIR,
                              extra_link_args=glib_link_args)]
 
     if sys.hexversion < 0x02020000:
@@ -92,9 +107,9 @@
         # This module requires Python >= 2.2
         ext_modules.append(Extension("xmms._xmmsconfig",
                                      ["src/_xmmsconfigmodule.c"],
-                                     include_dirs=glib_include_dirs,
+                                     include_dirs=glib_include_dirs+XMMSINCDIR,
                                      extra_compile_args=glib_compile_args,
-                                     libraries=["xmms"],
+                                     libraries=["xmms"], library_dirs=XMMSLIBDIR,
                                      extra_link_args=glib_link_args))
 
     # Trove classifiers picked up from the list at
