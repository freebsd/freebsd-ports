--- setup.py.orig	Sun May 12 22:37:06 2002
+++ setup.py	Sat May 18 23:03:58 2002
@@ -20,7 +20,7 @@
 # Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 # MA 02111-1307, USA.
 
-import os, string, sys
+import os, string, sys, re
 from distutils.core import setup, Extension
 
 # Notes:
@@ -34,9 +34,21 @@
 #     end of the gcc command, which is useless in this case. So, I use
 #     "include_dirs" instead.
 
+def patch4gcc3(fname):
+    instr = 0
+    cont = open(fname).readlines()
+    of = open(fname, 'w')
+    for l in cont:
+        instr = (instr+len(re.findall(r'(^")|([^\\]")', l))) % 2
+        print >>of, l[:-1] + ((not l.startswith('/*') and instr) and "\\n\\" or "")
+if 'patch' in sys.argv:
+    patch4gcc3('_xmmsmodule.c')
+    raise SystemExit
+
 PACKAGE = "pyxmms"
 VERSION = "1.06"
-GLIB_CONFIG = "glib-config"
+GLIB_CONFIG = os.environ['GLIB_CONFIG']
+XMMS_CONFIG = os.environ['XMMS_CONFIG']
 
 def main():
     glib_opts = {}
@@ -52,6 +64,9 @@
     glib_include_dirs = map(lambda s: s[2:],
                             string.split(glib_opts["cflags"], ' '))
 
+    XMMSINCDIR = re.findall('-I([^ ]+)', os.popen(XMMS_CONFIG+" --cflags").read())
+    XMMSLIBDIR = re.findall('-L([^ ]+)', os.popen(XMMS_CONFIG+" --libs").read())
+
     setup(name=PACKAGE,
           version=VERSION,
           description="A Python interface to XMMS",
@@ -69,8 +84,8 @@
           keywords=["xmms"],
           py_modules=["xmms"],
           ext_modules=[Extension("_xmms", ["_xmmsmodule.c"],
-                                 include_dirs=glib_include_dirs,
-                                 libraries=["xmms"],
+                                 include_dirs=glib_include_dirs+XMMSINCDIR,
+                                 libraries=["xmms"], library_dirs=XMMSLIBDIR,
                                  extra_link_args=[glib_opts["libs"]])])
 
 if __name__ == "__main__": main()
