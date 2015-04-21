--- setup.py.orig	2015-04-20 08:17:26 UTC
+++ setup.py
@@ -26,7 +26,5 @@ setup(name="pymetar", version=pymetar.__
       packages=[""],
       py_modules=["pymetar"],
       scripts=["bin/pymetar"],
-      data_files=[("share/doc/pymetar-%s" % pymetar.__version__,
-                   ['README', 'COPYING', 'THANKS', 'librarydoc.txt']),
-                  ("share/man/man1", ['pymetar.1'])]
+      data_files=[("man/man1", ['pymetar.1'])]
       )
