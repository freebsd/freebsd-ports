--- remote/node_modules/@parcel/watcher/binding.gyp.orig	2023-05-05 08:51:33 UTC
+++ remote/node_modules/@parcel/watcher/binding.gyp
@@ -34,7 +34,7 @@
             "ARCHS": ["arm64"]
           }
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           "sources": [
             "src/watchman/BSER.cc",
             "src/watchman/WatchmanBackend.cc",
@@ -46,6 +46,11 @@
             "WATCHMAN",
             "INOTIFY",
             "BRUTE_FORCE"
+          ]
+        }],
+	['OS=="freebsd"', {
+          "libraries": [
+            "-linotify"
           ]
         }],
         ['OS=="win"', {
