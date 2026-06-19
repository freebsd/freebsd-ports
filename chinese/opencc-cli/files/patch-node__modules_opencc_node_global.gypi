-- Add FreeBSD to the OS condition for C++20 and exception flags.
-- The original file only handles linux, mac, and win. FreeBSD needs
-- the same compiler flags as linux (-std=c++20, no -fno-exceptions).

--- node_modules/opencc/node/global.gypi.orig	2026-06-19 06:56:40 UTC
+++ node_modules/opencc/node/global.gypi
@@ -8,7 +8,7 @@
     ],
     "conditions": [
       [
-        "OS==\"linux\"",
+        "OS==\"linux\" or OS==\"freebsd\"",
         {
           "cflags": [
             "-std=c++20"
