--- trac/wiki/formatter.py.orig	Thu Aug 24 12:45:42 2006
+++ trac/wiki/formatter.py	Thu Aug 24 12:46:01 2006
@@ -307,7 +307,7 @@
             return '<img src="%s" alt="%s" />' % (url, title or text)
         if not url.startswith(self._local):
             return '<a class="ext-link" href="%s"%s><span class="icon">' \
-                   '</span>%s</a>' % (url, title_attr, text)
+                   '%s</span></a>' % (url, title_attr, text)
         else:
             return '<a href="%s"%s>%s</a>' % (url, title_attr, text)
 
