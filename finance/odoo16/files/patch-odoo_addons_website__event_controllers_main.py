--- odoo/addons/website_event/controllers/main.py.orig	2025-07-19 22:15:31 UTC
+++ odoo/addons/website_event/controllers/main.py
@@ -10,7 +10,7 @@ from dateutil.relativedelta import relativedelta
 from datetime import datetime, timedelta
 from dateutil.parser import parse
 from dateutil.relativedelta import relativedelta
-from werkzeug.datastructures import OrderedMultiDict
+from werkzeug.datastructures import MultiDict as OrderedMultiDict
 from werkzeug.exceptions import NotFound
 
 from odoo import fields, http, _
