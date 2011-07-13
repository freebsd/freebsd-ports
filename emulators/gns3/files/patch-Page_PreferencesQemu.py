--- src/GNS3/Ui/ConfigurationPages/Page_PreferencesQemu.py.orig	2011-07-03 00:06:36.000000000 +0200
+++ src/GNS3/Ui/ConfigurationPages/Page_PreferencesQemu.py	2011-07-03 00:07:26.000000000 +0200
@@ -97,7 +97,7 @@
             if sys.platform.startswith('win'):
                 self.conf.qemuwrapper_path = unicode('qemuwrapper.exe')
             else:
-                path = os.getcwd() + '/qemuwrapper/qemuwrapper.py'
+                path = '%%PREFIX%%/bin/qemuwrapper.py'
                 self.conf.qemuwrapper_path = unicode(path, errors='replace')
         
         # Default path to working directory
