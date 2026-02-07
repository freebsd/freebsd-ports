--- vispy/util/fonts/_freetype.py.orig	2023-09-09 07:33:03 UTC
+++ vispy/util/fonts/_freetype.py
@@ -14,6 +14,8 @@ import numpy as np
 from ._vispy_fonts import _vispy_fonts, _get_vispy_font_filename
 if sys.platform.startswith('linux'):
     from ...ext.fontconfig import find_font
+elif sys.platform.startswith('freebsd'):
+    from ...ext.fontconfig import find_font
 elif sys.platform.startswith('win'):
     from ._win32 import find_font  # noqa, analysis:ignore
 else:
