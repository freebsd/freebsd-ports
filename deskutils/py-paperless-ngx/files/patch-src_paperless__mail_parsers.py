--- src/paperless_mail/parsers.py.orig	2024-08-23 03:40:13 UTC
+++ src/paperless_mail/parsers.py
@@ -9,8 +9,8 @@ from django.conf import settings
 from django.utils.timezone import is_naive
 from django.utils.timezone import make_aware
 from gotenberg_client import GotenbergClient
-from gotenberg_client.options import MarginType
-from gotenberg_client.options import MarginUnitType
+from gotenberg_client.options import Measurement
+from gotenberg_client.options import MeasurementUnitType
 from gotenberg_client.options import PageMarginsType
 from gotenberg_client.options import PageSize
 from gotenberg_client.options import PdfAFormat
@@ -344,10 +344,10 @@ class MailDocumentParser(DocumentParser):
                     .resource(css_file)
                     .margins(
                         PageMarginsType(
-                            top=MarginType(0.1, MarginUnitType.Inches),
-                            bottom=MarginType(0.1, MarginUnitType.Inches),
-                            left=MarginType(0.1, MarginUnitType.Inches),
-                            right=MarginType(0.1, MarginUnitType.Inches),
+                            top=Measurement(0.1, MeasurementUnitType.Inches),
+                            bottom=Measurement(0.1, MeasurementUnitType.Inches),
+                            left=Measurement(0.1, MeasurementUnitType.Inches),
+                            right=Measurement(0.1, MeasurementUnitType.Inches),
                         ),
                     )
                     .size(PageSize(height=11.7, width=8.27))
@@ -426,10 +426,10 @@ class MailDocumentParser(DocumentParser):
             # Set page size, margins
             route.margins(
                 PageMarginsType(
-                    top=MarginType(0.1, MarginUnitType.Inches),
-                    bottom=MarginType(0.1, MarginUnitType.Inches),
-                    left=MarginType(0.1, MarginUnitType.Inches),
-                    right=MarginType(0.1, MarginUnitType.Inches),
+                    top=Measurement(0.1, MeasurementUnitType.Inches),
+                    bottom=Measurement(0.1, MeasurementUnitType.Inches),
+                    left=Measurement(0.1, MeasurementUnitType.Inches),
+                    right=Measurement(0.1, MeasurementUnitType.Inches),
                 ),
             ).size(
                 PageSize(height=11.7, width=8.27),
