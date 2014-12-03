--- setup.py.orig	2014-12-03 15:50:50 UTC
+++ setup.py
@@ -74,8 +74,8 @@ setup(
     packages=['barman', ],
     scripts=['bin/barman', ],
     data_files=[
-        ('share/man/man1', ['doc/barman.1']),
-        ('share/man/man5', ['doc/barman.5']),
+        ('man/man1', ['doc/barman.1']),
+        ('man/man5', ['doc/barman.5']),
     ],
     license='GPL-3.0',
     description=__doc__.split("\n")[0],
