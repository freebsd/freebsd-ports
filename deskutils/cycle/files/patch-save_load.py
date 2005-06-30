--- save_load.py.orig
+++ save_load.py
@@ -12,8 +12,12 @@
                         message='.*rotor module', module=__name__)
 
 import wx
-import os, os.path , cPickle, rotor, md5
+import os, os.path , cPickle, md5
 import cal_year
+try:
+    import rotor
+except:
+    import p_rotor as rotor
 
 def Save_Cycle(name='cycle', passwd='123'):
     """ Save the contents of our document to disk.
@@ -99,7 +103,8 @@
 
 #-------------------------------------------------------
 def get_f_name(name=""):
-    if '__WXMSW__' in wx.PlatformInfo:
+    #if '__WXMSW__' in wx.PlatformInfo:
+    if False:
         p=os.getcwd()+"\\data"
         f_name=p+"\\"+name
     else:
@@ -110,14 +115,14 @@
 
 #-------------------------------------------------------
 def set_color_default():
-    cal_year.cycle.colour_set={'begin':wx.NamedColour('red'),
-	'prog begin':wx.NamedColour('pink'),
+    cal_year.cycle.colour_set={'begin':wx.NamedColour('RED'),
+	'prog begin':wx.NamedColour('PINK'),
         'conception':wx.NamedColour('MAGENTA'),
-	'safe sex':wx.NamedColour('wheat'),
-	'fertile':wx.NamedColour('green yellow'),
+	'safe sex':wx.NamedColour('WHEAT'),
+	'fertile':wx.NamedColour('GREEN YELLOW'),
 	'ovule':wx.NamedColour('SPRING GREEN'),
-	'1-st tablet':wx.NamedColour('gold'),
-	'pause':wx.NamedColour('light blue'),
-	'next 1-st tablet':wx.NamedColour('pink')}
+	'1-st tablet':wx.NamedColour('GOLD'),
+	'pause':wx.NamedColour('LIGHT BLUE'),
+	'next 1-st tablet':wx.NamedColour('PINK')}
 
 
