--- setup.py.orig	2015-03-14 13:27:54 UTC
+++ setup.py
@@ -17,8 +17,8 @@ if sys.version_info[:3] < (2, 7, 0):
 
 
 data_files = []
-if platform.system() == 'Linux' or platform.system() == 'FreeBSD':
-    usr_share = os.path.join(sys.prefix, "share")
+if True:
+    usr_share = '%%PREFIX%%/share'
     data_files += [
         (os.path.join(usr_share, 'applications/'), ['electrum.desktop']),
         (os.path.join(usr_share, 'app-install', 'icons/'), ['icons/electrum.png'])
