--- setup.py.orig	2020-07-08 09:12:30 UTC
+++ setup.py
@@ -70,15 +70,15 @@ setup(
     url='http://www.pgbarman.org/',
     packages=find_packages(exclude=["tests"]),
     data_files=[
-        ('share/man/man1', ['doc/barman.1',
-                            'doc/barman-cloud-backup.1',
-                            'doc/barman-cloud-backup-list.1',
-                            'doc/barman-cloud-restore.1',
-                            'doc/barman-cloud-wal-archive.1',
-                            'doc/barman-cloud-wal-restore.1',
-                            'doc/barman-wal-archive.1',
-                            'doc/barman-wal-restore.1']),
-        ('share/man/man5', ['doc/barman.5']),
+        ('man/man1', ['doc/barman.1',
+                      'doc/barman-cloud-backup.1',
+                      'doc/barman-cloud-backup-list.1',
+                      'doc/barman-cloud-restore.1',
+                      'doc/barman-cloud-wal-archive.1',
+                      'doc/barman-cloud-wal-restore.1',
+                      'doc/barman-wal-archive.1',
+                      'doc/barman-wal-restore.1']),
+        ('man/man5', ['doc/barman.5']),
     ],
     entry_points={
         'console_scripts': [
