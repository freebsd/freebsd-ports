--- build/qt5.py.orig	2020-05-15 21:26:10 UTC
+++ build/qt5.py
@@ -43,7 +43,7 @@ import SCons.Scanner
 import SCons.Tool
 import SCons.Util
 
-class ToolQt5Warning(SCons.Warnings.Warning):
+class ToolQt5Warning(SCons.Warnings.SConsWarning):
     pass
 
 class GeneratedMocFileNotIncluded(ToolQt5Warning):
