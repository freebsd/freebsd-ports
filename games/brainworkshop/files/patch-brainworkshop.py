--- brainworkshop.py.orig	2021-05-08 11:38:01 UTC
+++ brainworkshop.py
@@ -41,7 +41,7 @@ def get_argv(arg):
             error_msg("Expected an argument following %s" % arg)
             exit(1)
 
-import random, os, sys, imp, socket, webbrowser, time, math, traceback, datetime, errno
+import random, os, sys, socket, webbrowser, time, math, traceback, datetime, errno
 if sys.version_info >= (3,0):
     import urllib.request, configparser as ConfigParser
     from io import StringIO
@@ -56,9 +56,9 @@ from datetime import date
 import gettext
 if sys.version_info >= (3,0):
     # TODO check if this is right
-    gettext.install('messages', localedir='res/i18n')
+    gettext.install('messages', localedir='%%DATADIR%%/res/i18n')
 else:
-    gettext.install('messages', localedir='res/i18n', unicode=True)
+    gettext.install('messages', localedir='%%DATADIR%%/res/i18n', unicode=True)
 
 # Clinical mode?  Clinical mode sets cfg.JAEGGI_MODE = True, enforces a minimal user
 # interface, and saves results into a binary file (default 'logfile.dat') which
@@ -137,14 +137,8 @@ def get_pyglet_media_Player():
     return my_player
 
 # some functions to assist in path determination
-def main_is_frozen():
-    return (hasattr(sys, "frozen") or # new py2exe
-        hasattr(sys, "importers") # old py2exe
-        or imp.is_frozen("__main__")) # tools/freeze
 def get_main_dir():
-    if main_is_frozen():
-        return os.path.dirname(sys.executable)
-    return sys.path[0]
+    return '%%DATADIR%%'
 
 def get_settings_path(name):
     '''Get a directory to save user preferences.
