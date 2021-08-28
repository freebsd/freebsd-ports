--- buildscripts/scons.py.orig	2021-08-23 09:10:10 UTC
+++ buildscripts/scons.py
@@ -18,14 +18,14 @@ SITE_TOOLS_DIR = os.path.join(MONGODB_ROOT, 'site_scon
 
 sys.path = [SCONS_DIR, SITE_TOOLS_DIR] + sys.path
 
-# pylint: disable=C0413
-from mongo.pip_requirements import verify_requirements, MissingRequirements
-
-try:
-    verify_requirements('etc/pip/compile-requirements.txt')
-except MissingRequirements as ex:
-    print(ex)
-    sys.exit(1)
+## pylint: disable=C0413
+#from mongo.pip_requirements import verify_requirements, MissingRequirements
+#
+#try:
+#    verify_requirements('etc/pip/compile-requirements.txt')
+#except MissingRequirements as ex:
+#    print(ex)
+#    sys.exit(1)
 
 try:
     import SCons.Script
