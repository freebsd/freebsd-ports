--- src/gui/qt_rcc.gypi.orig	2026-09-15 02:16:00 UTC
+++ src/gui/qt_rcc.gypi
@@ -34,7 +34,7 @@
   'variables': {
     'conditions': [
       ['target_platform=="Linux"', {
-        'rcc_path': '<!(pkg-config --variable=host_bins Qt5Core)/rcc',
+        'rcc_path': '<!(pkg-config --variable=libexecdir Qt6Core)/rcc',
       }, 'qt_dir', {
         'rcc_path': '<(qt_dir)/bin/rcc<(EXECUTABLE_SUFFIX)',
       }, {
