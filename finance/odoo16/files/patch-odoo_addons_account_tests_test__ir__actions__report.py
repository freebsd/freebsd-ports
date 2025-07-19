--- odoo/addons/account/tests/test_ir_actions_report.py.orig	2025-07-19 21:11:20 UTC
+++ odoo/addons/account/tests/test_ir_actions_report.py
@@ -2,7 +2,7 @@ import io
 import base64
 import io
 
-from PyPDF2 import PdfFileReader, PdfFileWriter
+from pypdf import PdfReader as PdfFileReader, PdfWriter as PdfFileWriter
 
 from odoo.addons.account.tests.common import AccountTestInvoicingCommon
 from odoo.exceptions import RedirectWarning
