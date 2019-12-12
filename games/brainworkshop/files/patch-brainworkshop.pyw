--- brainworkshop.pyw.orig	2019-11-18 21:08:09 UTC
+++ brainworkshop.pyw
@@ -56,9 +56,9 @@ from datetime import date
 import gettext
 if sys.version_info >= (3,0):
     # TODO check if this is right
-    gettext.install('messages', localedir='res/i18n')
+    gettext.install('messages', localedir='%%DATADIR%%/i18n')
 else:
-    gettext.install('messages', localedir='res/i18n', unicode=True)
+    gettext.install('messages', localedir='%%DATADIR%%/i18n', unicode=True)
 
 # Clinical mode?  Clinical mode sets cfg.JAEGGI_MODE = True, enforces a minimal user
 # interface, and saves results into a binary file (default 'logfile.dat') which
@@ -142,9 +142,7 @@ def main_is_frozen():
         hasattr(sys, "importers") # old py2exe
         or imp.is_frozen("__main__")) # tools/freeze
 def get_main_dir():
-    if main_is_frozen():
-        return os.path.dirname(sys.executable)
-    return sys.path[0]
+    return '%%DATADIR%%'
 
 def get_settings_path(name):
     '''Get a directory to save user preferences.
