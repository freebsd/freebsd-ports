--- setup.py.orig	2021-12-01 11:09:36 UTC
+++ setup.py
@@ -61,7 +61,7 @@ setup(
     packages=find_packages(exclude=["tests"]),
     data_files=[
         (
-            "share/man/man1",
+            "man/man1",
             [
                 "doc/barman.1",
                 "doc/barman-cloud-backup.1",
@@ -73,7 +73,7 @@ setup(
                 "doc/barman-wal-restore.1",
             ],
         ),
-        ("share/man/man5", ["doc/barman.5"]),
+        ("man/man5", ["doc/barman.5"]),
     ],
     entry_points={
         "console_scripts": [
