--- cvise.py.orig	2022-02-13 16:58:05 UTC
+++ cvise.py
@@ -283,7 +283,7 @@ if __name__ == '__main__':
     script = None
     if args.commands:
         with tempfile.NamedTemporaryFile(mode='w', delete=False, suffix='.sh') as script:
-            script.write('#!/bin/bash\n\n')
+            script.write('#!%%LOCALBASE%%/bin/bash\n\n')
             script.write(args.commands + '\n')
         os.chmod(script.name, 0o744)
         logging.info('Using temporary interestingness test: %s' % script.name)
