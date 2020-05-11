--- node_modules/spell-check/lib/locale-checker.coffee.orig	2020-05-09 06:41:08 UTC
+++ node_modules/spell-check/lib/locale-checker.coffee
@@ -78,6 +78,7 @@ class LocaleChecker
       searchPaths.push "/usr/share/hunspell"
       searchPaths.push "/usr/share/myspell"
       searchPaths.push "/usr/share/myspell/dicts"
+      searchPaths.push "/usr/local/share/hunspell"
 
     # OS X uses the following paths.
     if env.isDarwin()
