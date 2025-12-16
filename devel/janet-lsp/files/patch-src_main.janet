--- src/main.janet.orig	2025-12-15 16:13:59 UTC
+++ src/main.janet
@@ -16,12 +16,10 @@
 (use judge)
 
 (def version "0.0.11")
-(def commit
-  (with [proc (os/spawn ["git" "rev-parse" "--short" "HEAD"] :xp {:out :pipe})]
-    (let [[out] (ev/gather
-                  (ev/read (proc :out) :all)
-                  (os/proc-wait proc))]
-      (if out (string/trimr out) ""))))
+
+# `git rev-parse --short HEAD` is going to find the revision of the ports tree.
+# The tag should be enough so just supply a string for commit.
+(def commit "FreeBSD")
 
 (def jpm-defs (require "../libs/jpm-defs"))
 
