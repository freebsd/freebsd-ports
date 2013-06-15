--- ./setup.py.orig	2013-06-09 19:36:25.355293000 +0900
+++ ./setup.py	2013-06-09 19:45:13.675386000 +0900
@@ -15,14 +15,14 @@
 if (len(sys.argv) > 1 and (sys.argv[1] == "sdist")) or (platform.system() != 'Windows' and platform.system() != 'Darwin'):
     print "Including all files"
     data_files += [
-        ('/usr/share/applications/',['electrum.desktop']),
-        ('/usr/share/app-install/icons/',['icons/electrum.png'])
+        (os.path.join(sys.prefix, 'share', 'applications'),['electrum.desktop']),
+        (os.path.join(sys.prefix, 'share', 'app-install', 'icons'),['icons/electrum.png'])
     ]
     if not os.path.exists('locale'):
         os.mkdir('locale')
     for lang in os.listdir('locale'):
         if os.path.exists('locale/%s/LC_MESSAGES/electrum.mo'%lang):
-            data_files.append(  ('/usr/share/locale/%s/LC_MESSAGES'%lang, ['locale/%s/LC_MESSAGES/electrum.mo'%lang]) )
+            data_files.append( (os.path.join(sys.prefix, 'share/locale/%s/LC_MESSAGES'%lang), ['locale/%s/LC_MESSAGES/electrum.mo'%lang]) )
 
 data_files += [
     (util.appdata_dir(), ["data/README"]),
