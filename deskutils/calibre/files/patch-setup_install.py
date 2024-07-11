--- setup/install.py.orig	2024-06-28 03:34:16 UTC
+++ setup/install.py
@@ -355,7 +355,7 @@ class Bootstrap(Command):
 
     description = 'Bootstrap a fresh checkout of calibre from git to a state where it can be installed. Requires various development tools/libraries/headers'
     TRANSLATIONS_REPO = 'kovidgoyal/calibre-translations'
-    sub_commands = 'build iso639 iso3166 translations gui resources cacerts recent_uas'.split()
+    sub_commands = 'build iso639 iso3166 translations gui resources cacerts'.split()
 
     def add_options(self, parser):
         parser.add_option('--ephemeral', default=False, action='store_true',
