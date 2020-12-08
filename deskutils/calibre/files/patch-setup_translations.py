--- setup/translations.py.orig	2020-11-13 01:58:49 UTC
+++ setup/translations.py
@@ -159,7 +159,7 @@ class POT(Command):  # {{{
                             f.seek(0), f.truncate(), f.write('\n'.join(lines).encode('utf-8'))
                             break
                     else:
-                        raise SystemExit(f'Failed to add file_filter for {slug=} to config file')
+                        raise SystemExit(f'Failed to add file_filter for {slug} to config file')
                 self.git('add .tx/config')
             self.upload_pot(resource=slug)
             self.git(['add', dest])
