--- src/PkgBase/__init__.py.orig	2026-08-07 14:05:22 UTC
+++ src/PkgBase/__init__.py
@@ -3,12 +3,12 @@ import platform
 import platform
 
 # Version number
-PYTHONOCC_VERSION_MAJOR = 7
-PYTHONOCC_VERSION_MINOR = 9
-PYTHONOCC_VERSION_PATCH = 0
+PYTHONOCC_VERSION_MAJOR = 8
+PYTHONOCC_VERSION_MINOR = 0
+PYTHONOCC_VERSION_PATCH = 1
 
 # Empty for official releases, set to -dev, -rc1, etc for development releases
-PYTHONOCC_VERSION_DEVEL = ""
+PYTHONOCC_VERSION_DEVEL = "alpha"
 
 VERSION = f"{PYTHONOCC_VERSION_MAJOR}.{PYTHONOCC_VERSION_MINOR}.{PYTHONOCC_VERSION_PATCH}{PYTHONOCC_VERSION_DEVEL}"
 
