--- node_modules/@atom/watcher/binding.gyp.orig	1985-10-26 08:15:00 UTC
+++ node_modules/@atom/watcher/binding.gyp
@@ -66,7 +66,7 @@
                     "src/worker/windows/windows_worker_platform.cpp"
                 ]
             }],
-            ["OS=='linux'", {
+            ["OS=='linux' or OS=='freebsd'", {
                 "defines": [
                     'PLATFORM_LINUX'
                 ],
