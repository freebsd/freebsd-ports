--- odoo/addons/web_editor/models/ir_attachment.py	2021-09-04 18:48:12.921708000 -0500
+++ odoo/addons/web_editor/models/ir_attachment.py	2021-09-04 18:48:25.791645000 -0500
@@ -1,7 +1,7 @@
 # -*- coding: utf-8 -*-
 # Part of Odoo. See LICENSE file for full copyright and licensing details.
 
-from werkzeug.urls.urls import url_quote
+from werkzeug.urls import url_quote
 
 from odoo import api, models, fields, tools
 
