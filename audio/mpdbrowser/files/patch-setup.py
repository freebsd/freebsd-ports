--- _setup.py	2008-07-31 12:33:41.000000000 +0200
+++ setup.py	2008-12-26 16:19:16.000000000 +0100
@@ -36,7 +36,7 @@
 # Create mo files:
 if not os.path.exists("mo/"):
 	os.mkdir("mo/")
-for lang in ('de', 'pl', 'ru', 'fr', 'zh_CN', 'sv', 'es', 'fi', 'uk', 'it', 'cs', 'nl', 'pt_BR', 'da', 'be@latin'):
+for lang in ('fr', 'it', 'pl'):
 	pofile = "po/" + lang + ".po"
 	mofile = "mo/" + lang + "/mpdBrowser.mo"
 	if not os.path.exists("mo/" + lang + "/"):
@@ -45,7 +45,7 @@
 	os.system("msgfmt %s -o %s" % (pofile, mofile))
 
 setup(name='mpdBrowser',
-        version='0.9.0',
+        version='0.9.15',
         description='GTK+ client for the Music Player Daemon (MPD).',
         author='Bellegarde Cedric',
         author_email='gnumdk@gmail.com',
