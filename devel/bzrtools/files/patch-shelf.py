--- shelf.py.orig	Tue Aug 14 19:01:41 2007
+++ shelf.py	Mon Aug 20 17:16:40 2007
@@ -250,7 +250,7 @@
         if reverse:
             args.append('-R')
         if dry_run:
-            args.append('--dry-run')
+            args.append('--check')
             stderr = subprocess.PIPE
         else:
             stderr = None
