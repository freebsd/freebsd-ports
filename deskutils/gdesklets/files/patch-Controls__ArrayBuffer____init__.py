--- Controls/ArrayBuffer/__init__.py.orig	Mon Feb 28 14:07:04 2005
+++ Controls/ArrayBuffer/__init__.py	Mon Feb 28 14:07:25 2005
@@ -3,6 +3,10 @@
 # ArrayBuffer Class
 #
 #
+
+from libdesklets.controls import Control
+from IArrayBuffer import *
+
 class ArrayBuffer(Control, IArrayBuffer):
 
         #
