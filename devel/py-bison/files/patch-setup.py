--- ./setup.py.orig	2004-04-23 22:05:41.000000000 -0400
+++ ./setup.py	2007-12-20 11:34:57.000000000 -0500
@@ -24,6 +24,26 @@
     extra_link_args = []
     bison2pyscript = 'utils/bison2py'
     bisondynlibModule = "src/c/bisondynlib-linux.c"
+elif sys.platform == 'freebsd5':
+    libs = []
+    extra_link_args = []
+    bison2pyscript = 'utils/bison2py'
+    bisondynlibModule = "src/c/bisondynlib-linux.c"
+elif sys.platform == 'freebsd6':
+    libs = []
+    extra_link_args = []
+    bison2pyscript = 'utils/bison2py'
+    bisondynlibModule = "src/c/bisondynlib-linux.c"
+elif sys.platform == 'freebsd7':
+    libs = []
+    extra_link_args = []
+    bison2pyscript = 'utils/bison2py'
+    bisondynlibModule = "src/c/bisondynlib-linux.c"
+elif sys.platform == 'freebsd8':
+    libs = []
+    extra_link_args = []
+    bison2pyscript = 'utils/bison2py'
+    bisondynlibModule = "src/c/bisondynlib-linux.c"
 else:
     print "Sorry, your platform is presently unsupported"
     sys.exit(1)
