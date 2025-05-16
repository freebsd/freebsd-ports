--- tests/tests_e3/main/main_test.py.orig	2025-05-09 10:12:19 UTC
+++ tests/tests_e3/main/main_test.py
@@ -19,7 +19,7 @@ def test_mainprog():
         f.write(
             "\n".join(
                 (
-                    "#!/usr/bin/env python",
+                    "#!/usr/bin/env python%%PYTHON_VER%%",
                     "from e3.main import Main",
                     "import os",
                     'm = Main(name="testmain")',
@@ -44,7 +44,7 @@ def to_rework_modules_logging_limitations():
         f.write(
             "\n".join(
                 (
-                    "#!/usr/bin/env python",
+                    "#!/usr/bin/env python%%PYTHON_VER%%",
                     "from e3.main import Main",
                     "import requests",
                     "import logging",
@@ -79,7 +79,7 @@ def test_mainprog_with_console_logs():
         f.write(
             "\n".join(
                 (
-                    "#!/usr/bin/env python",
+                    "#!/usr/bin/env python%%PYTHON_VER%%",
                     "from e3.main import Main",
                     "import os",
                     'm = Main(name="testmain")',
@@ -111,7 +111,7 @@ def test_x86_64_windows_default():
         f.write(
             "\n".join(
                 (
-                    "#!/usr/bin/env python",
+                    "#!/usr/bin/env python%%PYTHON_VER%%",
                     "from e3.main import Main",
                     "m = Main(platform_args=True, default_x86_64_on_windows=True)",
                     "m.parse_args()",
@@ -128,7 +128,7 @@ def test_default_env_callback():
         f.write(
             "\n".join(
                 (
-                    "#!/usr/bin/env python",
+                    "#!/usr/bin/env python%%PYTHON_VER%%",
                     "from e3.main import Main",
                     "from e3.env import Env",
                     "def cb(args):",
@@ -157,7 +157,7 @@ def test_sigterm():
         f.write(
             "\n".join(
                 (
-                    "#!/usr/bin/env python",
+                    "#!/usr/bin/env python%%PYTHON_VER%%",
                     "from e3.main import Main",
                     "import os",
                     "import signal",
