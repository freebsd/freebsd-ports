--- tagger.py.orig	Thu Apr  6 16:48:21 2006
+++ tagger.py	Thu Apr  6 16:48:47 2006
@@ -54,6 +54,13 @@
 # ***** END LICENSE BLOCK *****
 
 try:
+ import psyco
+ assert psyco.__version__ >= 0x010300f0
+ psyco.full()
+except:
+ pass
+
+try:
     import wxversion
     wxversion.select(["2.6-unicode"])
 except:
