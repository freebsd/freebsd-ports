--- 3rd/bee.lua/compile/common.lua.orig	2026-01-10 05:26:24 UTC
+++ 3rd/bee.lua/compile/common.lua
@@ -210,7 +210,7 @@ lm:source_set "source_bee" {
         }
     },
     freebsd = {
-        sysincludes = "/usr/local/include",
+        sysincludes = "%LOCALBASE%/include",
         sources = need {
             "bsd",
             "posix",
@@ -294,8 +294,8 @@ lm:source_set "source_bee" {
         ldflags = "-pthread"
     },
     freebsd = {
-        links = "inotify",
-        linkdirs = "/usr/local/lib",
+        %LM_INOTIFY_LINK%
+        linkdirs = "%LOCALBASE%/lib",
         ldflags = "-pthread"
     },
     openbsd = {
