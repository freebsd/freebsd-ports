--- node_modules/fs-admin/binding.gyp.orig	1985-10-26 08:15:00 UTC
+++ node_modules/fs-admin/binding.gyp
@@ -37,7 +37,7 @@
             '$(SDKROOT)/System/Library/Frameworks/Security.framework',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'sources': [
             'src/fs-admin-linux.cc',
           ],
