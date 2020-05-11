--- docs/_ext/options.py.orig	2018-10-30 11:37:40 UTC
+++ docs/_ext/options.py
@@ -1,4 +1,4 @@
-from sphinx.util.compat import Directive
+from docutils.parsers.rst import Directive
 from docutils import nodes
 
 from noseOfYeti.plugins.support.spec_options import spec_options
