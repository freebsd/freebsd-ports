--- awscli/help.py.orig	2019-08-27 18:05:04 UTC
+++ awscli/help.py
@@ -107,13 +107,16 @@ class PosixHelpRenderer(PagingHelpRenderer):
 
     def _convert_doc_content(self, contents):
         man_contents = publish_string(contents, writer=manpage.Writer())
-        if not self._exists_on_path('groff'):
+        if self._exists_on_path('groff'):
+            cmdline = ['groff', '-m', 'man', '-T', 'ascii']
+        elif self._exists_on_path('mandoc'):
+            cmdline = ['mandoc', '-man', '-T', 'ascii']
+        else:
             raise ExecutableNotFoundError('groff')
-        cmdline = ['groff', '-m', 'man', '-T', 'ascii']
         LOG.debug("Running command: %s", cmdline)
         p3 = self._popen(cmdline, stdin=PIPE, stdout=PIPE, stderr=PIPE)
-        groff_output = p3.communicate(input=man_contents)[0]
-        return groff_output
+        man_output = p3.communicate(input=man_contents)[0]
+        return man_output
 
     def _send_output_to_pager(self, output):
         cmdline = self.get_pager_cmdline()
