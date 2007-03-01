--- shelf.py.bak	Tue Feb 27 16:17:33 2007
+++ shelf.py	Tue Feb 27 16:40:17 2007
@@ -250,7 +250,7 @@
         if reverse:
             args.append('-R')
         if dry_run:
-            args.append('--dry-run')
+            args.append('--check')
             stdout = stderr = subprocess.PIPE
         else:
             stdout = stderr = None
