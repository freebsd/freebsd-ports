--- odoo/addons/account_edi/models/account_edi_format.py.orig	2025-07-19 21:53:05 UTC
+++ odoo/addons/account_edi/models/account_edi_format.py
@@ -7,9 +7,9 @@ try:
 from odoo.tools import html_escape
 from odoo.exceptions import RedirectWarning
 try:
-    from PyPDF2.errors import PdfReadError
+    from pypdf.errors import PdfReadError
 except ImportError:
-    from PyPDF2.utils import PdfReadError
+    from pypdf.utils import PdfReadError
 
 from lxml import etree
 from struct import error as StructError
