--- ./setup.py.orig	2013-04-07 16:33:32.000000000 +0400
+++ ./setup.py	2013-06-15 18:56:59.000000000 +0400
@@ -15,14 +15,14 @@
 if (len(sys.argv) > 1 and (sys.argv[1] == "sdist")) or (platform.system() != 'Windows' and platform.system() != 'Darwin'):
     print "Including all files"
     data_files += [
-        ('/usr/share/applications/',['electrum.desktop']),
-        ('/usr/share/app-install/icons/',['icons/electrum.png'])
+        (os.path.join('%%PREFIX%%', 'share', 'applications'),['electrum.desktop']),
+        (os.path.join('%%PREFIX%%', 'share', 'app-install', 'icons'),['icons/electrum.png'])
     ]
     if not os.path.exists('locale'):
         os.mkdir('locale')
     for lang in os.listdir('locale'):
         if os.path.exists('locale/%s/LC_MESSAGES/electrum.mo'%lang):
-            data_files.append(  ('/usr/share/locale/%s/LC_MESSAGES'%lang, ['locale/%s/LC_MESSAGES/electrum.mo'%lang]) )
+            data_files.append( (os.path.join('%%PREFIX%%', 'share/locale/%s/LC_MESSAGES'%lang), ['locale/%s/LC_MESSAGES/electrum.mo'%lang]) )
 
 data_files += [
     (util.appdata_dir(), ["data/README"]),
