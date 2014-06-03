--- setup.py.orig	2014-03-16 14:01:35.000000000 +0100
+++ setup.py	2014-06-03 11:12:40.621312285 +0200
@@ -15,9 +15,7 @@
 if sys.version_info[:3] < (2, 6, 0):
     sys.exit("Error: Electrum requires Python version >= 2.6.0...")
 
-usr_share = '/usr/share'
-if not os.access(usr_share, os.W_OK):
-    usr_share = os.getenv("XDG_DATA_HOME", os.path.join(os.getenv("HOME"), ".local", "share"))
+usr_share = '%%PREFIX%%/share'
 
 data_files = []
 if (len(sys.argv) > 1 and (sys.argv[1] == "sdist")) or (platform.system() != 'Windows' and platform.system() != 'Darwin'):
