--- cycle.py.orig	2005-09-15 03:23:46 UTC
+++ cycle.py
@@ -9,6 +9,9 @@
 import os, sys, gettext
 import locale
 
+prefix = os.path.split(os.path.dirname(sys.argv[0]))[0]
+sys.path.append(os.path.join(prefix, 'lib', 'cycle'))
+
 import wxversion 
 wxversion.ensureMinimal('2.5.3')
 import wx
