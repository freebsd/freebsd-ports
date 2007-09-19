--- gr-wxgui/src/python/stdgui.py.orig	Sat Feb 24 10:05:41 2007
+++ gr-wxgui/src/python/stdgui.py	Sat Feb 24 10:06:13 2007
@@ -21,6 +21,8 @@
 
 '''A simple wx gui for GNU Radio applications'''
 
+import wxversion
+wxversion.select('2.6')
 import wx
 import sys
 from gnuradio import gr
