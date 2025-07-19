--- odoo/addons/website_slides/models/slide_slide.py.orig	2025-07-19 21:31:58 UTC
+++ odoo/addons/website_slides/models/slide_slide.py
@@ -7,7 +7,7 @@ import requests
 import logging
 import re
 import requests
-import PyPDF2
+import pypdf as PyPDF2
 
 from dateutil.relativedelta import relativedelta
 from markupsafe import Markup
