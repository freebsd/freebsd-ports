--- buildscripts/scons.py.orig	2024-07-23 11:11:41 UTC
+++ buildscripts/scons.py
@@ -18,15 +18,6 @@ sys.path = [SCONS_DIR, SITE_TOOLS_DIR] + sys.path
 
 sys.path = [SCONS_DIR, SITE_TOOLS_DIR] + sys.path
 
-# pylint: disable=C0413
-from mongo.pip_requirements import verify_requirements, MissingRequirements
-
-try:
-    verify_requirements()
-except MissingRequirements as ex:
-    print(ex)
-    sys.exit(1)
-
 try:
     import SCons.Script
 except ImportError as import_err:
