--- node_modules/spellchecker/binding.gyp.orig	1985-10-26 08:15:00 UTC
+++ node_modules/spellchecker/binding.gyp
@@ -4,7 +4,7 @@
       ['OS=="mac"', {
         'spellchecker_use_hunspell%': 'true',
       }],
-      ['OS=="linux"', {
+      ['OS=="linux" or OS=="freebsd"', {
         'spellchecker_use_hunspell': 'true',
       }],
       ['OS=="win"', {
@@ -53,7 +53,7 @@
              'src/transcoder_win.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'sources': [
              'src/spellchecker_linux.cc',
              'src/transcoder_posix.cc',
