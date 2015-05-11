--- setup.py.orig	2015-04-25 02:55:24 UTC
+++ setup.py
@@ -18,7 +18,7 @@ if sys.version_info[:3] < (2, 7, 0):
 
 data_files = []
 if platform.system() in [ 'Linux', 'FreeBSD', 'DragonFly']:
-    usr_share = os.path.join(sys.prefix, "share")
+    usr_share = '%%PREFIX%%/share'
     data_files += [
         (os.path.join(usr_share, 'applications/'), ['electrum.desktop']),
         (os.path.join(usr_share, 'pixmaps/'), ['icons/electrum.png'])
