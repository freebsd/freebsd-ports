--- src/documents/admin.py.orig	2019-01-27 13:48:05 UTC
+++ src/documents/admin.py
@@ -9,7 +9,7 @@ from django.http import HttpResponseRedirect
 from django.templatetags.static import static
 from django.urls import reverse
 from django.utils.html import format_html, format_html_join
-from django.utils.http import urlquote
+from urllib.parse import quote
 from django.utils.safestring import mark_safe
 from djangoql.admin import DjangoQLSearchMixin
 
@@ -252,7 +254,7 @@ class DocumentAdmin(DjangoQLSearchMixin, CommonAdmin):
             "name": opts.verbose_name,
             "obj": format_html(
                 '<a href="{}">{}</a>',
-                urlquote(request.path),
+                quote(request.path),
                 obj
             ),
         }
