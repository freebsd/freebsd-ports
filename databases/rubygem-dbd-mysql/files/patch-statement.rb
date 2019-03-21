--- lib/dbd/mysql/statement.rb.orig	2018-04-15 10:29:03 UTC
+++ lib/dbd/mysql/statement.rb
@@ -20,7 +20,7 @@ module DBI::DBD::Mysql
         # binding.
         #
         def bind_param(param, value, attribs)
-            raise InterfaceError, "only ? parameters supported" unless param.is_a? Fixnum
+            raise InterfaceError, "only ? parameters supported" unless param.is_a? Integer
             @params[param-1] = value 
         end
 
