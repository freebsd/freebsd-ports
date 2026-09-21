--- src/build_mozc.py.orig	2026-09-15 02:12:59 UTC
+++ src/build_mozc.py
@@ -620,7 +620,7 @@ def GypMain(options, unused_args):
     gyp_options.extend(['-D', 'qt_dir='])
 
     # Check if Qt libraries are installed.
-    if not PkgExists('Qt5Core', 'Qt5Gui', 'Qt5Widgets'):
+    if not PkgExists('Qt6Core'):
       PrintErrorAndExit('Qt is required to build GUI Tool. '
                         'Specify --noqt to skip building GUI Tool.')
 
