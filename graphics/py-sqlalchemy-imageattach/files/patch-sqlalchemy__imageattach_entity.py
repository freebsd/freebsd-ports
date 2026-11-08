Description: Use html.escape and detect FieldStorage-like uploads by their
  file attribute (cgi was removed in Python 3.13).
Issue ID: none
Changeset: none
TODO: Upstream is dead (no commits or releases since 2017-10); keep locally.

--- sqlalchemy_imageattach/entity.py.orig	2017-10-08 12:58:43 UTC
+++ sqlalchemy_imageattach/entity.py
@@ -72,7 +72,7 @@ Or you can resize the image to make thum
 """
 from __future__ import division
 
-import cgi
+import html
 import io
 import numbers
 import shutil
@@ -338,7 +338,7 @@ class Image(object):
         return store.locate(self)
 
     def __html__(self):
-        u = cgi.escape(self.locate())
+        u = html.escape(self.locate())
         return '<img src="{0}" width="{1}" height="{2}">'.format(u, *self.size)
 
     __doc__ = append_docstring_attributes(
@@ -677,7 +677,7 @@ class BaseImageSet(object):
 
         """
 
-        if isinstance(file, cgi.FieldStorage):
+        if not hasattr(file, 'read') and hasattr(file, 'file'):
             file = file.file
 
         data = io.BytesIO()
@@ -962,7 +962,7 @@ class BaseImageSet(object):
     def __html__(self):
         if not self:
             return ''
-        url = cgi.escape(self.locate())
+        url = html.escape(self.locate())
         size = self.require_original().size
         return '<img src="{0}" width="{1}" height="{2}">'.format(url, *size)
 
