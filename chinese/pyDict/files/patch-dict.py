--- ./dict.py.orig	Wed Oct 17 22:02:16 2007
+++ ./dict.py	Tue Nov  6 18:28:47 2007
@@ -1,4 +1,5 @@
 #!/usr/bin/env python
+# -*- coding: big5 -*-
 #-------------------------------------------------
 # this is a program that utilize the library of xdict.
 # Made by Daniel Gau <r90057@im.ntu.edu.tw>
@@ -322,16 +323,17 @@
         """Get the word this object describes."""
         return self.word
 
-from gtk import *
-from GDK import *
+prop = [" "," "," ","<<形容詞>>","<<副詞>>","art. ","<<連接詞>>","int.  ","<<名詞>>"," "," ","num. ", 	"prep. "," ","pron.  ","<<動詞>>","<<助動詞>>","<<非及物動詞>>","<<及物動詞>>","vbl. "," ","st. ", "pr. ","<<過去分詞>>","<<複數>>","ing. "," ","<<形容詞>>","<<副詞>>","pla. ","pn. "," "]
+
 from string import split,replace,strip,lstrip,find,lower
-import GtkExtra
 import sys,os,string
+if os.environ.has_key('DISPLAY') and len(sys.argv) == 1:
+ from gtk import *
+ from GDK import *
+ import GtkExtra
 
 
-prop = [" "," "," ","<<形容詞>>","<<副詞>>","art. ","<<連接詞>>","int.  ","<<名詞>>"," "," ","num. ", 	"prep. "," ","pron.  ","<<動詞>>","<<助動詞>>","<<非及物動詞>>","<<及物動詞>>","vbl. "," ","st. ", "pr. ","<<過去分詞>>","<<複數>>","ing. "," ","<<形容詞>>","<<副詞>>","pla. ","pn. "," "]
-
-class Pref(GtkDialog):
+ class Pref(GtkDialog):
     def __init__(self,modal=TRUE,app=None):
         GtkDialog.__init__(self)
 	self.connect("destroy", self.quit)
@@ -482,7 +484,7 @@
     def quit(self,w=None,event=None):
     	self.hide()
 
-class HelpDialog(GtkDialog):
+ class HelpDialog(GtkDialog):
     def __init__(self,modal=TRUE,file=None):
         GtkDialog.__init__(self)
 	self.set_title("pyDict Help")
@@ -542,7 +544,7 @@
         self.quit()
 
 
-class App(GtkWindow):
+ class App(GtkWindow):
     def __init__(self):
         GtkWindow.__init__(self,WINDOW_TOPLEVEL)
         self.create_vars()
