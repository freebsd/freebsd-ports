--- docs/conf.py.orig	2026-02-19 07:47:01 UTC
+++ docs/conf.py
@@ -4,6 +4,8 @@ from pathlib import Path
 from datetime import datetime, timezone
 from pathlib import Path
 
+sys.path.insert(0, '%%VIRTUALENV_WHEEL%%')
+
 from virtualenv.version import __version__
 
 company = "PyPA"
