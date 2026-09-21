--- src/gui/qt_uic.gypi.orig	2026-09-15 02:22:01 UTC
+++ src/gui/qt_uic.gypi
@@ -34,7 +34,7 @@
   'variables': {
     'conditions': [
       ['target_platform=="Linux"', {
-        'uic_path': '<!(pkg-config --variable=host_bins Qt5Core)/uic',
+        'uic_path': '<!(pkg-config --variable=libexecdir Qt6Core)/uic',
       }, 'qt_dir', {
         'uic_path': '<(qt_dir)/bin/uic<(EXECUTABLE_SUFFIX)',
       }, {
