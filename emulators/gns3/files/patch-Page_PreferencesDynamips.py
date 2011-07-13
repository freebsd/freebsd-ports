--- src/GNS3/Ui/ConfigurationPages/Page_PreferencesDynamips.py.orig	2011-07-03 00:11:46.000000000 +0200
+++ src/GNS3/Ui/ConfigurationPages/Page_PreferencesDynamips.py	2011-07-03 00:32:42.000000000 +0200
@@ -55,7 +55,9 @@
         # Default path to dynamips executable
         if self.conf.path == '' and sys.platform.startswith('win'):
             self.conf.path = unicode('dynamips-wxp.exe')
-            
+        else:
+            self.conf.path = unicode('%%LOCALBASE%%/bin/dynamips')
+    
         # Default path to working directory
         if self.conf.workdir == '':
             if os.environ.has_key("TEMP"):
