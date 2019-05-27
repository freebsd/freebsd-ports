# Skip the test (module) if gdk_pixbuf can't be loaded
# TODO: Report/resolve/PR upstream

--- cairocffi/test_pixbuf.py.orig	2019-02-06 21:50:58 UTC
+++ cairocffi/test_pixbuf.py
@@ -15,7 +15,12 @@ import zlib
 
 import pytest
 
-from . import constants, pixbuf
+from . import constants
+
+try:
+    from . import pixbuf
+except OSError:
+    pytestmark = pytest.mark.skip('Could not find/load gdk_pixbuf-2.0')
 
 PNG_BYTES = base64.b64decode(
     b'iVBORw0KGgoAAAANSUhEUgAAAAMAAAACCAYAAACddGYaAAAAE0lEQV'
