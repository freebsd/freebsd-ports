--- lib/glib.py.orig	2016-01-15 19:42:55 UTC
+++ lib/glib.py
@@ -1,5 +1,5 @@
 # This file is part of MyPaint.
-# Copyright (C) 2015 by Andrew Chadwick <a.t.chadwick@gmail.com>
+# Copyright (C) 2015-2016 by the MyPaint Development Team.
 #
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -19,11 +19,12 @@ unicode, and may not even be UTF-8). Thi
 ## Imports
 
 import sys
-from logging import getLogger
-logger = getLogger(__name__)
+import logging
 
 from gi.repository import GLib
 
+logger = logging.getLogger(__name__)
+
 
 ## File path getter functions
 
@@ -35,7 +36,6 @@ def filename_to_unicode(opsysstring):
     :returns: the converted filename
     :rtype: unicode
 
-    >>> from gi.repository import GLib
     >>> filename_to_unicode('/ascii/only/path')
     u'/ascii/only/path'
     >>> filename_to_unicode(None) is None
@@ -54,7 +54,12 @@ def filename_to_unicode(opsysstring):
     # Other systems are dependent in opaque ways on the environment.
     if not isinstance(opsysstring, str):
         raise TypeError("Argument must be bytes")
-    ustring = GLib.filename_to_utf8(opsysstring, -1, 0, 0)
+    # This function's annotation seems to vary quite a bit.
+    # See https://github.com/mypaint/mypaint/issues/634
+    try:
+        ustring, _, _ = GLib.filename_to_utf8(opsysstring, -1)
+    except TypeError:
+        ustring = GLib.filename_to_utf8(opsysstring, -1, 0, 0)
     if ustring is None:
         raise UnicodeDecodeError(
             "GLib failed to convert %r to a UTF-8 string. "
