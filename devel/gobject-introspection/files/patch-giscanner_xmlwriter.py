--- giscanner/xmlwriter.py.orig
+++ giscanner/xmlwriter.py
@@ -67,7 +67,7 @@ def collect_attributes(tag_name, attributes, self_indent,
     return attr_value
 
 
-with LibtoolImporter:
+with LibtoolImporter(None, None):
     from giscanner._giscanner import collect_attributes
 
 
