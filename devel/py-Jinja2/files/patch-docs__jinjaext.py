--- ./docs/jinjaext.py.orig	2013-06-27 15:33:08.000000000 +0200
+++ ./docs/jinjaext.py	2013-06-27 15:33:13.000000000 +0200
@@ -23,7 +23,7 @@
 from pygments.token import Keyword, Name, Comment, String, Error, \
      Number, Operator, Generic
 from jinja2 import Environment, FileSystemLoader
-from jinja2.utils import next
+from jinja2._compat import next
 
 
 def parse_rst(state, content_offset, doc):
