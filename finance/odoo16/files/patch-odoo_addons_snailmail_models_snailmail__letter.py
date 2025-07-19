--- odoo/addons/snailmail/models/snailmail_letter.py.orig	2025-07-19 20:56:13 UTC
+++ odoo/addons/snailmail/models/snailmail_letter.py
@@ -4,7 +4,7 @@ import io
 import base64
 import io
 
-from PyPDF2 import PdfFileReader, PdfFileWriter
+from pypdf import PdfReader as PdfFileReader, PdfWriter as PdfFileWriter
 from reportlab.platypus import Frame, Paragraph, KeepInFrame
 from reportlab.lib.units import mm
 from reportlab.lib.pagesizes import A4
