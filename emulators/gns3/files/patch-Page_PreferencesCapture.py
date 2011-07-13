--- src/GNS3/Ui/ConfigurationPages/Page_PreferencesCapture.py.orig	2011-07-03 00:10:04.000000000 +0200
+++ src/GNS3/Ui/ConfigurationPages/Page_PreferencesCapture.py	2011-07-03 00:10:29.000000000 +0200
@@ -52,7 +52,7 @@
             elif sys.platform.startswith('win'):
                 self.conf.cap_cmd = unicode("C:\Program Files\Wireshark\wireshark.exe %c")
             else:
-                self.conf.cap_cmd = unicode("/usr/bin/wireshark %c")
+                self.conf.cap_cmd = unicode("%%LOCALBASE%%/bin/wireshark %c")
 
         if self.conf.workdir == '':
             if os.environ.has_key("TEMP"):
