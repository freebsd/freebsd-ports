--- node_modules/@atom/nsfw/binding.gyp.orig	1985-10-26 08:15:00 UTC
+++ node_modules/@atom/nsfw/binding.gyp
@@ -97,6 +97,9 @@
             ["OS=='freebsd'", {
                 "include_dirs": [
                     "/usr/local/include"
+                ],
+                "ldflags": [
+                    "-L/usr/local/lib", "-linotify"
                 ]
             }],
         ]
