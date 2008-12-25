Index: engine/SCons/compat/__init__.py
===================================================================
--- engine/SCons/compat/__init__.py (revision 2695)
+++ engine/SCons/compat/__init__.py (working copy)
@@ -167,11 +167,17 @@
     del shlex
     import_as('_scons_shlex', 'shlex')
 
-try:
-    import subprocess
-except ImportError:
-    # Pre-2.4 Python has no subprocess module.
-    import_as('_scons_subprocess', 'subprocess')
+#try:
+#    import subprocess
+#except ImportError:
+#    # Pre-2.4 Python has no subprocess module.
+#    import_as('_scons_subprocess', 'subprocess')
+
+# Import subprocess unconditionally to avoid possible race conditions in
+# the official subprocess API. If there are API versions without known
+# problems, we can version-check and use the original subprocess module
+# in these cases.
+import_as('_scons_subprocess', 'subprocess')
 
 import sys
 try:


