--- bugz/configfile.py.orig	2015-09-20 16:13:33 UTC
+++ bugz/configfile.py
@@ -9,7 +9,7 @@ from bugz.log import log_error
 def load_config(UserConfig=None):
     parser = configparser.ConfigParser(default_section='default')
     DefaultConfigs = sorted(glob.glob(sys.prefix + '/share/pybugz.d/*.conf'))
-    SystemConfigs = sorted(glob.glob('/etc/pybugz.d/*.conf'))
+    SystemConfigs = sorted(glob.glob(sys.prefix + '/etc/pybugz.d/*.conf'))
     if UserConfig is not None:
         UserConfig = os.path.expanduser(UserConfig)
     else:
