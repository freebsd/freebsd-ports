--- setup.py.orig	2025-04-18 19:16:24 UTC
+++ setup.py
@@ -7,6 +7,8 @@ try:
 
 try:
     import multiprocessing
+    # Python 3.14 uses forkserver, which fails. Force spawn.
+    multiprocessing.set_start_method('spawn', force=True)
 except ImportError:
     multiprocessing = None
 
@@ -233,5 +235,5 @@ def long_desc_from_readme():
         long_description = re.compile(r"^\.\. highlight:: \w+$", re.M).sub("", long_description)
         return long_description
 
-
-setup(cmdclass=cmdclass, ext_modules=ext_modules, long_description=long_desc_from_readme())
+if __name__ == '__main__':
+    setup(cmdclass=cmdclass, ext_modules=ext_modules, long_description=long_desc_from_readme())
