--- setup.py.orig	2021-07-06 11:19:31 UTC
+++ setup.py
@@ -31,6 +31,7 @@ setuptools.setup(
     packages=setuptools.find_packages(),
     py_modules=["pymetar"],
     scripts=["bin/pymetar"],
+    data_files=[("share/man/man1", ['pymetar.1'])],
     classifiers=(
     "Programming Language :: Python :: 3",
     "License :: OSI Approved :: GNU General Public License v2 or later (GPLv2+)", 
