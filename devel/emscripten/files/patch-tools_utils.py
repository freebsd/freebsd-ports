-- allow EMSCRIPTEN_ROOT environment variable to override __rootpath__

--- tools/utils.py.orig	2026-04-22 03:51:10 UTC
+++ tools/utils.py
@@ -19,7 +19,7 @@ from pathlib import Path
 
 from . import diagnostics
 
-__rootpath__ = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
+__rootpath__ = os.environ.get('EMSCRIPTEN_ROOT') or os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
 WINDOWS = sys.platform.startswith('win')
 MACOS = sys.platform == 'darwin'
 
