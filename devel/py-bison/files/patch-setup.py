--- setup.py.orig	2004-04-24 06:05:41.000000000 +0400
+++ setup.py	2011-09-29 22:14:01.000000000 +0400
@@ -24,6 +24,11 @@
     extra_link_args = []
     bison2pyscript = 'utils/bison2py'
     bisondynlibModule = "src/c/bisondynlib-linux.c"
+elif 'freebsd' in sys.platform:
+    libs = []
+    extra_link_args = []
+    bison2pyscript = 'utils/bison2py'
+    bisondynlibModule = "src/c/bisondynlib-linux.c"
 else:
     print "Sorry, your platform is presently unsupported"
     sys.exit(1)
