--- setup.py.orig	Wed Nov 19 19:52:54 2003
+++ setup.py	Wed Dec 17 10:24:39 2003
@@ -20,7 +20,7 @@
 # Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 # MA 02111-1307, USA.
 
-import os, string, sys, distutils.dist
+import os, string, sys, distutils.dist, re
 from distutils.core import setup, Extension
 
 # Note:
@@ -32,7 +32,8 @@
 
 PACKAGE = "pyxmms"
 VERSION = "2.02"
-GLIB_CONFIG = "glib-config"
+GLIB_CONFIG = os.environ['GLIB_CONFIG']
+XMMS_CONFIG = os.environ['XMMS_CONFIG']
 
 
 def get_glib_config():
@@ -70,13 +71,16 @@
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
@@ -92,9 +96,9 @@
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
