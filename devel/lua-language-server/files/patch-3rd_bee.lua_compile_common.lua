--- 3rd/bee.lua/compile/common.lua.orig	2025-12-03 14:18:20 UTC
+++ 3rd/bee.lua/compile/common.lua
@@ -207,7 +207,7 @@ lm:source_set "source_bee" {
         }
     },
     freebsd = {
-        sysincludes = "/usr/local/include",
+        sysincludes = "%LOCALBASE%/include",
         sources = need {
             "bsd",
             "posix",
@@ -291,8 +291,8 @@ lm:source_set "source_bee" {
         ldflags = "-pthread"
     },
     freebsd = {
-        links = "inotify",
-        linkdirs = "/usr/local/lib",
+        %INOTIFY%
+        linkdirs = "%LOCALBASE%/lib",
         ldflags = "-pthread"
     },
     openbsd = {
