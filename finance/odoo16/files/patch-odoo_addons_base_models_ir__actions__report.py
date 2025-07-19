--- odoo/addons/base/models/ir_actions_report.py.orig	2025-07-19 20:52:24 UTC
+++ odoo/addons/base/models/ir_actions_report.py
@@ -24,7 +24,7 @@ from reportlab.pdfbase.pdfmetrics import getFont, Type
 from contextlib import closing
 from reportlab.graphics.barcode import createBarcodeDrawing
 from reportlab.pdfbase.pdfmetrics import getFont, TypeFace
-from PyPDF2 import PdfFileWriter, PdfFileReader
+from pypdf import PdfWriter as PdfFileWriter, PdfReader as PdfFileReader
 from collections import OrderedDict
 from collections.abc import Iterable
 from PIL import Image, ImageFile
@@ -32,9 +32,9 @@ try:
 ImageFile.LOAD_TRUNCATED_IMAGES = True
 
 try:
-    from PyPDF2.errors import PdfReadError
+    from pypdf.errors import PdfReadError
 except ImportError:
-    from PyPDF2.utils import PdfReadError
+    from pypdf.utils import PdfReadError
 
 _logger = logging.getLogger(__name__)
 
