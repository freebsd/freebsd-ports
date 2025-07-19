--- odoo/addons/account/models/ir_actions_report.py.orig	2025-07-19 21:08:49 UTC
+++ odoo/addons/account/models/ir_actions_report.py
@@ -2,12 +2,12 @@ try:
 from collections import OrderedDict
 from zlib import error as zlib_error
 try:
-    from PyPDF2.errors import PdfReadError
+    from pypdf.errors import PdfReadError
 except ImportError:
-    from PyPDF2.utils import PdfReadError
+    from pypdf.utils import PdfReadError
 
 try:
-    from PyPDF2.errors import DependencyError
+    from pypdf.errors import DependencyError
 except ImportError:
     DependencyError = NotImplementedError
 
