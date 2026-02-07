--- odoo/addons/website/models/website.py.orig	2025-07-19 22:52:31 UTC
+++ odoo/addons/website/models/website.py
@@ -17,7 +17,7 @@ from werkzeug import urls
 from lxml import etree, html
 from psycopg2 import sql
 from werkzeug import urls
-from werkzeug.datastructures import OrderedMultiDict
+from werkzeug.datastructures import MultiDict as OrderedMultiDict
 from werkzeug.exceptions import NotFound
 from markupsafe import Markup
 
