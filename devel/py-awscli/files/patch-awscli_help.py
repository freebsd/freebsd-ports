--- awscli/help.py.orig	2022-11-14 19:07:18 UTC
+++ awscli/help.py
@@ -109,7 +109,7 @@ class PosixHelpRenderer(PagingHelpRenderer):
         if self._exists_on_path('groff'):
             cmdline = ['groff', '-m', 'man', '-T', 'ascii']
         elif self._exists_on_path('mandoc'):
-            cmdline = ['mandoc', '-T', 'ascii']
+            cmdline = ['mandoc', '-man', '-T', 'ascii']
         else:
             raise ExecutableNotFoundError('groff or mandoc')
         LOG.debug("Running command: %s", cmdline)
