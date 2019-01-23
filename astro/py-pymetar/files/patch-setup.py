--- setup.py.orig	2018-12-25 17:48:03 UTC
+++ setup.py
@@ -31,9 +31,7 @@ setuptools.setup(
     packages=setuptools.find_packages(),
     py_modules=["pymetar"],
     scripts=["bin/pymetar"],
-    data_files=[("share/doc/pymetar-%s" % pymetar.__version__,
-                 ['README.md', 'COPYING', 'THANKS']),
-                ("share/man/man1", ['pymetar.1'])],
+    data_files=[("man/man1", ['pymetar.1'])],
     classifiers=(
     "Programming Language :: Python :: 3",
     "License :: OSI Approved :: GNU General Public License v2 or later (GPLv2+)", 
