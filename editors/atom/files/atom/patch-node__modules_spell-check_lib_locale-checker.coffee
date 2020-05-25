--- node_modules/spell-check/lib/locale-checker.coffee.orig	2020-05-18 17:31:39 UTC
+++ node_modules/spell-check/lib/locale-checker.coffee
@@ -73,6 +73,7 @@ class LocaleChecker
         searchPaths.push "/usr/share/hunspell"
         searchPaths.push "/usr/share/myspell"
         searchPaths.push "/usr/share/myspell/dicts"
+        searchPaths.push "/usr/local/share/hunspell"
 
       if env.isDarwin()
         searchPaths.push "/"
