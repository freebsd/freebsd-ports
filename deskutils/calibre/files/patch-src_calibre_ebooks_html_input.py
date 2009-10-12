--- src/calibre/ebooks/html/input.py.orig	2009-10-11 19:20:45.000000000 +0400
+++ src/calibre/ebooks/html/input.py	2009-10-11 19:21:09.000000000 +0400
@@ -20,7 +20,7 @@
 from calibre.customize.conversion import InputFormatPlugin
 from calibre.ebooks.chardet import xml_to_unicode
 from calibre.customize.conversion import OptionRecommendation
-from calibre.constants import islinux
+from calibre.constants import islinux, isfreebsd
 from calibre import unicode_path
 from calibre.utils.localization import get_lang
 
@@ -344,7 +344,7 @@
         self.added_resources = {}
         self.log = log
         for path, href in htmlfile_map.items():
-            if not islinux:
+            if not (islinux or isfreebsd):
                 path = path.lower()
             self.added_resources[path] = href
         self.urlnormalize, self.DirContainer = urlnormalize, DirContainer
@@ -409,7 +409,7 @@
         link = os.path.abspath(link)
         if not os.access(link, os.R_OK):
             return link_
-        if not islinux:
+        if not (islinux or isfreebsd):
             link = link.lower()
         if link not in self.added_resources:
             bhref = os.path.basename(link)
