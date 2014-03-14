--- setup.py.orig	2007-02-07 14:04:48.000000000 +0100
+++ setup.py	2014-03-08 10:02:22.000000000 +0100
@@ -19,13 +19,13 @@
 # Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 # Boston, MA  02110-1301 USA.
 
-import os, string, sys, distutils.dist
+import os, string, sys, distutils.dist, re
 from distutils.core import setup, Extension
 
 PACKAGE = "pyxmms"
 VERSION = "2.07"
-GLIB_CONFIG = "glib-config"
-
+GLIB_CONFIG = os.environ['GLIB_CONFIG']
+XMMS_CONFIG = os.environ['XMMS_CONFIG']
 
 def get_glib_config():
     """Get the compilation and link parameters for glib."""
@@ -62,19 +62,22 @@
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
                              extra_link_args=glib_link_args),
                    Extension("xmms._xmmsconfig",
                              ["src/_xmmsconfigmodule.c"],
-                             include_dirs=glib_include_dirs,
+                             include_dirs=glib_include_dirs+XMMSINCDIR,
                              extra_compile_args=glib_compile_args,
-                             libraries=["xmms"],
+                             libraries=["xmms"], library_dirs=XMMSLIBDIR,
                              extra_link_args=glib_link_args)]
 
     # Trove classifiers picked up from the list at
