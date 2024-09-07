--- vispy/util/fonts/_triage.py.orig	2023-09-09 07:31:17 UTC
+++ vispy/util/fonts/_triage.py
@@ -10,6 +10,9 @@ from ._vispy_fonts import _vispy_fonts
 if sys.platform.startswith('linux'):
     from ._freetype import _load_glyph
     from ...ext.fontconfig import _list_fonts
+elif sys.platform.startswith('freebsd'):
+    from ._freetype import _load_glyph
+    from ...ext.fontconfig import _list_fonts
 elif sys.platform == 'darwin':
     from ._quartz import _load_glyph, _list_fonts
 elif sys.platform.startswith('win'):
