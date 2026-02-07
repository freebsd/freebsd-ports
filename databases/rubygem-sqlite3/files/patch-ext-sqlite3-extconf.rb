--- ext/sqlite3/extconf.rb.orig	2024-05-22 11:16:02 UTC
+++ ext/sqlite3/extconf.rb
@@ -136,8 +136,6 @@ module Sqlite3
       end
 
       def minimal_recipe
-        require "mini_portile2"
-
         MiniPortile.new(libname, sqlite3_config[:version]).tap do |recipe|
           if sqlite_source_dir
             recipe.source_directory = sqlite_source_dir
