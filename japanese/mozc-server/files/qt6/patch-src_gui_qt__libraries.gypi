--- src/gui/qt_libraries.gypi.orig	2026-09-15 05:11:10 UTC
+++ src/gui/qt_libraries.gypi
@@ -99,8 +99,8 @@
       ]
     }],
     ['target_platform=="Linux"', {
-      'cflags': ['<!@(pkg-config --cflags Qt5Widgets Qt5Gui Qt5Core)'],
-      'libraries': ['<!@(pkg-config --libs Qt5Widgets Qt5Gui Qt5Core)'],
+      'cflags': ['<!@(pkg-config --cflags Qt6Widgets Qt6Gui Qt6Core)'],
+      'libraries': ['<!@(pkg-config --libs Qt6Widgets Qt6Gui Qt6Core)'],
     }],
     # Workarounds related with clang.
     ['(_toolset=="target" and compiler_target=="clang") or '
