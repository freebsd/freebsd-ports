--- lib/dbd/pg/statement.rb.orig	2018-03-17 05:55:55 UTC
+++ lib/dbd/pg/statement.rb
@@ -18,7 +18,7 @@ class DBI::DBD::Pg::Statement < DBI::Bas
         @result = nil
         @bindvars = []
         @prepared = false
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::ProgrammingError.new(err.message)
     end
 
@@ -58,7 +58,7 @@ class DBI::DBD::Pg::Statement < DBI::Bas
         end
 
         @result = DBI::DBD::Pg::Tuples.new(@db, pg_result)
-    rescue PGError, RuntimeError => err
+    rescue PG::Error, RuntimeError => err
         raise DBI::ProgrammingError.new(err.message)
     end
 
