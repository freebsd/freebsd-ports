--- setup.py.orig	2019-05-14 16:37:28 UTC
+++ setup.py
@@ -71,10 +71,10 @@ setup(
     url='http://www.pgbarman.org/',
     packages=find_packages(exclude=["tests"]),
     data_files=[
-        ('share/man/man1', ['doc/barman.1',
-                            'doc/barman-wal-archive.1',
-                            'doc/barman-wal-restore.1']),
-        ('share/man/man5', ['doc/barman.5']),
+        ('man/man1', ['doc/barman.1',
+                      'doc/barman-wal-archive.1',
+                      'doc/barman-wal-restore.1']),
+        ('man/man5', ['doc/barman.5']),
     ],
     entry_points={
         'console_scripts': [
