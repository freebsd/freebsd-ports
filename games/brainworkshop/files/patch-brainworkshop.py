--- brainworkshop.py.orig	2023-01-15 15:36:39 UTC
+++ brainworkshop.py
@@ -69,9 +69,9 @@ if sys.version_info >= (3,0):
 
 if sys.version_info >= (3,0):
     # TODO check if this is right
-    gettext.install('messages', localedir='res/i18n')
+    gettext.install('messages', localedir='%%DATADIR%%/res/i18n')
 else:
-    gettext.install('messages', localedir='res/i18n', unicode=True)
+    gettext.install('messages', localedir='%%DATADIR%%/res/i18n', unicode=True)
 
 # Clinical mode?  Clinical mode sets cfg.JAEGGI_MODE = True, enforces a minimal user
 # interface, and saves results into a binary file (default 'logfile.dat') which
@@ -150,12 +150,8 @@ def get_pyglet_media_Player():
     return my_player
 
 # some functions to assist in path determination
-def main_is_frozen():
-    return hasattr(sys, "frozen") # py2exe
 def get_main_dir():
-    if main_is_frozen():
-        return os.path.dirname(sys.executable)
-    return sys.path[0]
+    return '%%DATADIR%%'
 
 def get_settings_path(name):
     '''Get a directory to save user preferences.
