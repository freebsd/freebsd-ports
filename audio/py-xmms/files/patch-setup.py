--- setup.py.orig	Mon Mar 18 01:08:13 2002
+++ setup.py	Tue Mar 19 09:42:54 2002
@@ -34,9 +34,12 @@
 #     end of the gcc command, which is useless in this case. So, I use
 #     "include_dirs" instead.
 
+import os, re
+
 PACKAGE = "PyXMMS"
 VERSION = "1.02"
-GLIB_CONFIG = "glib-config"
+GLIB_CONFIG = os.environ['GLIB_CONFIG']
+XMMS_CONFIG = os.environ['XMMS_CONFIG']
 
 def main():
     glib_opts = {}
@@ -51,6 +54,9 @@
     # Suppress the -I in each -Idir output by glib-config --cflags (ugly)
     glib_include_dirs = map(lambda s: s[2:],
                             string.split(glib_opts["cflags"], ' '))
+    
+    XMMSINCDIR = re.findall('-I([^ ]+)', os.popen(XMMS_CONFIG+" --cflags").read())
+    XMMSLIBDIR = re.findall('-L([^ ]+)', os.popen(XMMS_CONFIG+" --libs").read())
 
     setup(name=PACKAGE,
           version=VERSION,
@@ -69,8 +75,9 @@
           keywords=["xmms"],
           py_modules=["xmms"],
           ext_modules=[Extension("_xmms", ["_xmmsmodule.c"],
-                                 include_dirs=glib_include_dirs,
+                                 include_dirs=glib_include_dirs+XMMSINCDIR,
                                  libraries=["xmms"],
+				 library_dirs=XMMSLIBDIR,
                                  extra_link_args=[glib_opts["libs"]])])
 
 if __name__ == "__main__": main()
