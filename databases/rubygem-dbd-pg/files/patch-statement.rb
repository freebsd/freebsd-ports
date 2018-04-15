--- lib/dbd/pg/statement.rb.orig	2018-04-15 06:18:20 UTC
+++ lib/dbd/pg/statement.rb
@@ -18,7 +18,7 @@ class DBI::DBD::Pg::Statement < DBI::Bas
         @result = nil
         @bindvars = []
         @prepared = false
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::ProgrammingError.new(err.message)
     end
 
@@ -36,7 +36,7 @@ class DBI::DBD::Pg::Statement < DBI::Bas
         # replace DBI::Binary object by oid returned by lo_import
         @bindvars.collect! do |var|
             if var.is_a? DBI::Binary then
-                oid = @db.__blob_create(PGconn::INV_WRITE)
+                oid = @db.__blob_create(PG::Connection::INV_WRITE)
                 @db.__blob_write(oid, var.to_s)
                 oid
             else
@@ -58,7 +58,7 @@ class DBI::DBD::Pg::Statement < DBI::Bas
         end
 
         @result = DBI::DBD::Pg::Tuples.new(@db, pg_result)
-    rescue PGError, RuntimeError => err
+    rescue PG::Error, RuntimeError => err
         raise DBI::ProgrammingError.new(err.message)
     end
 
