--- docs/_ext/show_tests.py.orig	2018-10-30 11:37:40 UTC
+++ docs/_ext/show_tests.py
@@ -1,6 +1,6 @@
 from docutils.nodes import fully_normalize_name as normalize_name
 from sphinx.directives.code import LiteralInclude
-from sphinx.util.compat import Directive
+from docutils.parsers.rst import Directive
 from pinocchio.spec import testName
 from docutils import nodes
 import inspect
