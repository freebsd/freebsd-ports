--- setup.py.orig	Sat Apr 24 10:05:41 2004
+++ setup.py	Mon Jul 26 14:20:35 2004
@@ -24,6 +24,16 @@
     extra_link_args = []
     bison2pyscript = 'utils/bison2py'
     bisondynlibModule = "src/c/bisondynlib-linux.c"
+elif sys.platform == 'freebsd4':
+    libs = []
+    extra_link_args = []
+    bison2pyscript = 'utils/bison2py'
+    bisondynlibModule = "src/c/bisondynlib-linux.c"
+elif sys.platform == 'freebsd5':
+    libs = []
+    extra_link_args = []
+    bison2pyscript = 'utils/bison2py'
+    bisondynlibModule = "src/c/bisondynlib-linux.c"
 else:
     print "Sorry, your platform is presently unsupported"
     sys.exit(1)
