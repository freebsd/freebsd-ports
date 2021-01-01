--- node_modules/tabs/lib/tab-bar-view.coffee.orig	2019-01-24 00:42:27 UTC
+++ node_modules/tabs/lib/tab-bar-view.coffee
@@ -462,7 +462,7 @@ class TabBarView
 
   updateTabScrolling: (value) ->
     if value is 'platform'
-      @tabScrolling = (process.platform is 'linux')
+      @tabScrolling = (process.platform is 'linux' or process.platform is 'freebsd')
     else
       @tabScrolling = value
 
