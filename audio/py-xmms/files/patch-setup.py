--- setup.py.orig	Sun Apr  7 22:52:01 2002
+++ setup.py	Sun May  5 00:02:33 2002
@@ -20,7 +20,7 @@
 # Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 # MA 02111-1307, USA.
 
-import os, string, sys
+import os, string, sys, re
 from distutils.core import setup, Extension
 
 # Notes:
@@ -36,7 +36,8 @@
 
 PACKAGE = "pyxmms"
 VERSION = "1.03"
-GLIB_CONFIG = "glib-config"
+GLIB_CONFIG = os.environ['GLIB_CONFIG']
+XMMS_CONFIG = os.environ['XMMS_CONFIG']
 
 def main():
     glib_opts = {}
@@ -52,6 +53,9 @@
     glib_include_dirs = map(lambda s: s[2:],
                             string.split(glib_opts["cflags"], ' '))
 
+    XMMSINCDIR = re.findall('-I([^ ]+)', os.popen(XMMS_CONFIG+" --cflags").read())
+    XMMSLIBDIR = re.findall('-L([^ ]+)', os.popen(XMMS_CONFIG+" --libs").read())
+
     setup(name=PACKAGE,
           version=VERSION,
           description="A Python interface to XMMS",
@@ -69,8 +73,8 @@
           keywords=["xmms"],
           py_modules=["xmms"],
           ext_modules=[Extension("_xmms", ["_xmmsmodule.c"],
-                                 include_dirs=glib_include_dirs,
-                                 libraries=["xmms"],
+                                 include_dirs=glib_include_dirs+XMMSINCDIR,
+                                 libraries=["xmms"], library_dirs=XMMSLIBDIR,
                                  extra_link_args=[glib_opts["libs"]])])
 
 if __name__ == "__main__": main()
