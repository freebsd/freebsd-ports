--- setup.py.orig	2021-12-20 07:25:37 UTC
+++ setup.py
@@ -13,9 +13,9 @@ for line in open("./fudge/__init__.py"):
 assert version
 
 extra_setup = {}
-if sys.version_info >= (3,):
-    extra_setup['use_2to3'] = True
-    # extra_setup['use_2to3_fixers'] = ['your.fixers']
+#if sys.version_info >= (3,):
+#    extra_setup['use_2to3'] = True
+# extra_setup['use_2to3_fixers'] = ['your.fixers']
 
 setup(
     name='fudge',
