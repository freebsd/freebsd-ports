--- node_modules/spell-check/lib/checker-env.coffee.orig	2020-05-09 06:40:15 UTC
+++ node_modules/spell-check/lib/checker-env.coffee
@@ -1,5 +1,5 @@
 module.exports =
-  isLinux: -> /linux/.test process.platform
+  isLinux: -> /(linux|freebsd)/.test process.platform
   isWindows: -> /win32/.test process.platform # TODO: Windows < 8 or >= 8
   isDarwin: -> /darwin/.test process.platform
   preferHunspell: -> !!process.env.SPELLCHECKER_PREFER_HUNSPELL
