--- ext/sqlite3/extconf.rb.orig	2023-04-08 07:40:49 UTC
+++ ext/sqlite3/extconf.rb
@@ -130,8 +130,6 @@ module Sqlite3
       end
 
       def minimal_recipe
-        require "mini_portile2"
-
         MiniPortile.new(libname, sqlite3_config[:version]).tap do |recipe|
           if sqlite_source_dir
             recipe.source_directory = sqlite_source_dir
