--- node_modules/nslog/binding.gyp.orig	1985-10-26 08:15:00 UTC
+++ node_modules/nslog/binding.gyp
@@ -33,7 +33,7 @@
             'src/nslog_win.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'sources': [
             'src/nslog_linux.cc',
           ],
