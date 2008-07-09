--- setup.py	2008-01-18 13:57:53.000000000 +0100
+++ setup.py.port	2008-01-23 19:03:05.000000000 +0100
@@ -58,7 +58,8 @@
 DATA_FILES += [('share/gtksourceview-1.0/language-specs', ['gtksourceview-1.0/language-specs/pgn.lang'])]
 
 # Manpages
-DATA_FILES += [('share/man/man1', ['manpages/pychess.1.gz'])]
+if not os.environ.has_key('NO_INSTALL_MANPAGES'):
+    DATA_FILES += [('man/man1', ['manpages/pychess.1.gz'])]
 
 # Language
 pofile = "LC_MESSAGES/pychess"
