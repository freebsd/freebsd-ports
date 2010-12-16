--- ./setup.py.orig	2010-12-16 11:38:10.000000000 +0100
+++ ./setup.py	2010-12-16 11:38:42.000000000 +0100
@@ -90,7 +90,8 @@
 DATA_FILES += [('share/gtksourceview-1.0/language-specs', ['gtksourceview-1.0/language-specs/pgn.lang'])]
 
 # Manpages
-DATA_FILES += [('share/man/man1', ['manpages/pychess.1.gz'])]
+if not os.environ.has_key('NO_INSTALL_MANPAGES'):
+    DATA_FILES += [('man/man1', ['manpages/pychess.1.gz'])]
 
 # Language
 pofile = "LC_MESSAGES/pychess"
