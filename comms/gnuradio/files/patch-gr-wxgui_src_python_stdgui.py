--- gr-wxgui/src/python/stdgui.py.orig	2007-11-05 19:54:57.000000000 -0500
+++ gr-wxgui/src/python/stdgui.py	2008-01-03 13:20:37.000000000 -0500
@@ -21,6 +21,8 @@
 
 '''A simple wx gui for GNU Radio applications'''
 
+import wxversion
+wxversion.select('2.6')
 import wx
 import sys
 from gnuradio import gr
