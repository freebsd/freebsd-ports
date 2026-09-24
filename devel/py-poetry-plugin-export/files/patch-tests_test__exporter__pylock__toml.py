-- Update the expected output for the OR marker with a selected extra.
-- With the corrected marker simplification the package is included
-- unconditionally when the extra is selected, so no marker line is written.
-- See https://github.com/python-poetry/poetry-plugin-export/issues/218

--- tests/test_exporter_pylock_toml.py.orig	2026-09-24 02:39:43 UTC
+++ tests/test_exporter_pylock_toml.py
@@ -10,7 +10,6 @@ from poetry.core.packages.package import Package
 from poetry.core.constraints.version import Version
 from poetry.core.packages.dependency_group import MAIN_GROUP
 from poetry.core.packages.package import Package
-from poetry.core.version.markers import BaseMarker
 from poetry.factory import Factory
 from poetry.packages import Locker as BaseLocker
 from poetry.repositories import Repository
@@ -975,7 +974,7 @@ extras = []
             {"main"},
             {"extra1"},
             'python_version >= "3.6" or extra == "extra1"',
-            "*" if hasattr(BaseMarker, "apply") else 'python_version >= "3.6"',
+            "*",
         ),
         ({"main"}, {"extra1"}, 'python_version >= "3.6" and extra != "extra1"', ""),
     ],
