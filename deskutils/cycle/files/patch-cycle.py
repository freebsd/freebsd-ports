--- cycle.py.orig
+++ cycle.py
@@ -8,8 +8,16 @@
 #===================================================    
 import os, sys, gettext
 import locale
+
+prefix = os.path.split(os.path.dirname(sys.argv[0]))[0]
+sys.path.append(os.path.join(prefix, 'lib', 'cycle'))
+
+#import wxversion 
+#wxversion.select("2.4")
+#wxversion.ensureMinimal('2.5.3')
 import wx
 import wx.html
+import wx.lib.colourdb
 
 from cal_year import *
 from save_load import *
@@ -19,36 +27,49 @@
 
 import gettext
 import __builtin__
-lang_find=0
-if os.environ.has_key('LANGUAGE'):
-    env_language=os.environ['LANGUAGE']
-    for s_lang in env_language.split(':'): # if set more languages
-	os.environ['LANGUAGE']=s_lang
-	try:
-	    dl=locale.getdefaultlocale()
-	    lang=[ dl[0][0:2] ]
-	    l=gettext.translation('cycle', msg_dir, lang)
-	    __builtin__.__dict__['_'] = lambda s: l.ugettext(s).encode(dl[1])
-	    _('try decode this string')
-	    lang_find=1
-	    break #language is finded
-	except:
-	    pass
-else: #for Windows
+lang_find=False
+#if not '__WXMSW__' in wx.PlatformInfo:
+if True:
+    for lang_env_var in ('LANGUAGE', 'LC_ALL', 'LC_CTYPE', 'LANG'):
+	if lang_find:
+	    break
+	if os.environ.has_key(lang_env_var):
+	    env_language=os.environ[lang_env_var]
+	    for s_lang in env_language.split(':'): # if set more languages
+		os.environ[lang_env_var]=s_lang
+		try:
+		    dl=locale.getdefaultlocale()
+		    lang=[ dl[0][0:2] ]
+		    l=gettext.translation('cycle', msg_dir, lang)
+		    if wx.USE_UNICODE:
+			__builtin__.__dict__['_'] = lambda s: l.ugettext(s)
+		    else:
+			__builtin__.__dict__['_'] = lambda s: l.ugettext(s).encode(dl[1])
+		    _('try decode this string')
+		    lang_find=True
+		    break #language was found
+		    #print "Using language \"%s\"." % (lang)
+		except:
+		    pass
+else: #for MS Windows
     try:
         dl=locale.getdefaultlocale()
         lang=[ dl[0][0:2] ]
 	l=gettext.translation('cycle', msg_dir, lang)
-	__builtin__.__dict__['_'] = lambda s: l.ugettext(s).encode(dl[1])
+	if wx.USE_UNICODE:
+	    __builtin__.__dict__['_'] = lambda s: l.ugettext(s)
+	else:
+	    __builtin__.__dict__['_'] = lambda s: l.ugettext(s).encode(dl[1])
 	_('try decode this string')
-	lang_find=1
+	lang_find=True
+	#print "Using language \"%s\"." % (lang)
     except:
         pass
 
 if not lang_find:
     __builtin__.__dict__['_'] = lambda s: s
     lang=[""]
-
+    #print "Language NOT found."
 
 class MyFrame(wx.Frame):
     def __init__(self, parent, ID, title):
@@ -79,35 +100,33 @@
 	tb = self.CreateToolBar(wx.TB_HORIZONTAL|wx.NO_BORDER)
 	tb.SetToolBitmapSize( wx.Size(24,24) )
 
-	bmp_path = 'bitmaps/'
-
-	SetToolPath(self, tb, 10, bmp_path + 'dec.png', _('Dec Year'))
+	SetToolPath(self, tb, 10, os.path.join(bitmaps_dir,'dec.png'), _('Dec Year'))
 	wx.EVT_TOOL(self, 10, self.OnDecYear)
 
-	SetToolPath(self, tb, 20, bmp_path + 'curr.png', _('Current Year'))
+	SetToolPath(self, tb, 20, os.path.join(bitmaps_dir,'curr.png'), _('Current Year'))
 	wx.EVT_TOOL(self, 20, self.OnCurrent)
 
-	SetToolPath(self, tb, 30, bmp_path + 'inc.png', _('Inc Year'))
+	SetToolPath(self, tb, 30, os.path.join(bitmaps_dir,'inc.png'), _('Inc Year'))
 	wx.EVT_TOOL(self, 30, self.OnIncYear)
 
 	tb.SetToolSeparation(50)
 	tb.AddSeparator()
 	
-	SetToolPath(self, tb, 40, bmp_path + 'legend.png', _('Legend'))
+	SetToolPath(self, tb, 40, os.path.join(bitmaps_dir,'legend.png'), _('Legend'))
 	wx.EVT_TOOL(self, 40, self.Legend)
 	
-	SetToolPath(self, tb, 50, bmp_path + 'set.png', _('Settings'))
+	SetToolPath(self, tb, 50, os.path.join(bitmaps_dir,'set.png'), _('Settings'))
 	wx.EVT_TOOL(self, 50, self.Settings)
 	
-	SetToolPath(self, tb, 55, bmp_path + 'help.png', _('Help'))
+	SetToolPath(self, tb, 55, os.path.join(bitmaps_dir,'help.png'), _('Help'))
 	wx.EVT_TOOL(self, 55, self.Info)
 
-#	SetToolPath(self, tb, 57, bmp_path + 'help.png', _('Print'))
+#	SetToolPath(self, tb, 57, os.path.join(bitmaps_dir,'help.png'), _('Print'))
 #	wx.EVT_TOOL(self, 57, self.test)
 
 	tb.AddSeparator()
 
-	SetToolPath(self, tb, 60, bmp_path + 'exit.png', _('Exit'))
+	SetToolPath(self, tb, 60, os.path.join(bitmaps_dir,'exit.png'), _('Exit'))
 	wx.EVT_TOOL(self, 60, self.TimeToQuit)
 
 	tb.Realize()
@@ -163,6 +182,7 @@
 
 class MyApp(wx.App):
     def OnInit(self):
+	wx.lib.colourdb.updateColourDB()
 	ret=first_login()
 	if ret=='bad_login':
 	    return True
