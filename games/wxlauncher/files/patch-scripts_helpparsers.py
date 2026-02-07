--- scripts/helpparsers.py.orig	2020-09-26 12:23:32 UTC
+++ scripts/helpparsers.py
@@ -6,16 +6,16 @@ import traceback
 import sys
 import shutil
 
-import HTMLParser
+import html.parser
 
 from dataclasses import Tag
 from utilfunctions import update_attribute, change_filename
 
-class OutputParser(HTMLParser.HTMLParser):
+class OutputParser(html.parser.HTMLParser):
   """The class is designed to be used as a base class.  It will output the same html structure as the input file into a file like object (only needs write)."""
       
   def __init__(self, file, *args, **kwargs):
-    HTMLParser.HTMLParser.__init__(self, *args, **kwargs)
+    html.parser.HTMLParser.__init__(self, *args, **kwargs)
     
     if hasattr(file, 'write'):
       self.outputfile = file
