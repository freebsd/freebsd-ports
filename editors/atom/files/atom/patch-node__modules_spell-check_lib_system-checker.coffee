--- node_modules/spell-check/lib/system-checker.coffee.orig	2019-12-27 08:04:33 UTC
+++ node_modules/spell-check/lib/system-checker.coffee
@@ -65,6 +65,9 @@ class SystemChecker
       searchPaths.push "/usr/share/myspell"
       searchPaths.push "/usr/share/myspell/dicts"
 
+    if /freebsd/.test process.platform
+      searchPaths.push "/usr/local/share/hunspell"
+
     # OS X uses the following paths.
     if /darwin/.test process.platform
       searchPaths.push "/"
