--- ./setup.py.orig	2010-12-27 18:06:29.000000000 +0100
+++ ./setup.py	2014-05-14 23:15:44.000000000 +0200
@@ -62,9 +62,7 @@
 # Create mo files:
 if not os.path.exists("mo/"):
 	os.mkdir("mo/")
-for lang in ('de', 'pl', 'ru', 'fr', 'zh_CN', 'sv', 'es', 'fi', 'uk', 'it', 'cs', \
-             'nl', 'pt_BR', 'da', 'be@latin', 'et', 'ca', 'ar', 'tr', 'el_GR', 'sk', \
-             'zh_TW', 'ja', 'sl'):
+for lang in ('fr', 'it', 'pl'):
 	pofile = "po/" + lang + ".po"
 	mofile = "mo/" + lang + "/mpdBrowser.mo"
 	if not os.path.exists("mo/" + lang + "/"):
