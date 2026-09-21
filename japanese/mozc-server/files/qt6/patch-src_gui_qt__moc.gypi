--- src/gui/qt_moc.gypi.orig	2026-09-15 02:15:11 UTC
+++ src/gui/qt_moc.gypi
@@ -34,7 +34,7 @@
   'variables': {
     'conditions': [
       ['target_platform=="Linux"', {
-        'moc_path': '<!(pkg-config --variable=host_bins Qt5Core)/moc',
+        'moc_path': '<!(pkg-config --variable=libexecdir Qt6Core)/moc',
       }, 'qt_dir', {
         'moc_path': '<(qt_dir)/bin/moc<(EXECUTABLE_SUFFIX)',
       }, {
