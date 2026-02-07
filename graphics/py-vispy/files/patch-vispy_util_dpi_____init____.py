--- vispy/util/dpi/__init__.py.orig	2023-09-09 07:30:09 UTC
+++ vispy/util/dpi/__init__.py
@@ -11,6 +11,8 @@ __all__ = ['get_dpi']
 
 if sys.platform.startswith('linux'):
     from ._linux import get_dpi
+elif sys.platform.startswith('freebsd'):
+    from ._linux import get_dpi
 elif sys.platform == 'darwin':
     from ._quartz import get_dpi
 elif sys.platform.startswith('win'):
