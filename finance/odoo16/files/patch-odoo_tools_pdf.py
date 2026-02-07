--- odoo/tools/pdf.py.orig	2025-07-19 20:58:30 UTC
+++ odoo/tools/pdf.py
@@ -12,28 +12,9 @@ from reportlab.pdfgen import canvas
 from reportlab.lib.units import cm
 from reportlab.lib.utils import ImageReader
 from reportlab.pdfgen import canvas
+from pypdf import PdfWriter as PdfFileWriter, PdfReader as PdfFileReader
 
-try:
-    # class were renamed in PyPDF2 > 2.0
-    # https://pypdf2.readthedocs.io/en/latest/user/migration-1-to-2.html#classes
-    from PyPDF2 import PdfReader
-    import PyPDF2
-    # monkey patch to discard unused arguments as the old arguments were not discarded in the transitional class
-    # https://pypdf2.readthedocs.io/en/2.0.0/_modules/PyPDF2/_reader.html#PdfReader
-    class PdfFileReader(PdfReader):
-        def __init__(self, *args, **kwargs):
-            if "strict" not in kwargs and len(args) < 2:
-                kwargs["strict"] = True  # maintain the default
-            kwargs = {k:v for k, v in kwargs.items() if k in ('strict', 'stream')}
-            super().__init__(*args, **kwargs)
-
-    PyPDF2.PdfFileReader = PdfFileReader
-    from PyPDF2 import PdfFileWriter, PdfFileReader
-    PdfFileWriter._addObject = PdfFileWriter._add_object
-except ImportError:
-    from PyPDF2 import PdfFileWriter, PdfFileReader
-
-from PyPDF2.generic import DictionaryObject, NameObject, ArrayObject, DecodedStreamObject, NumberObject, createStringObject, ByteStringObject
+from pypdf.generic import DictionaryObject, NameObject, ArrayObject, DecodedStreamObject, NumberObject, create_string_object as createStringObject, ByteStringObject
 
 try:
     from fontTools.ttLib import TTFont
