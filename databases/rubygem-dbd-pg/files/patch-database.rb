--- lib/dbd/pg/database.rb.orig	2018-03-17 05:55:55 UTC
+++ lib/dbd/pg/database.rb
@@ -48,7 +48,7 @@ class DBI::DBD::Pg::Database < DBI::Base
         hash['tty'] ||= ''
         hash['port'] = hash['port'].to_i unless hash['port'].nil? 
 
-        @connection = PGconn.new(hash['host'], hash['port'], hash['options'], hash['tty'], 
+        @connection = PG::Connection.new(hash['host'], hash['port'], hash['options'], hash['tty'], 
                                  hash['dbname'] || hash['database'], user, auth)
 
         @exec_method = :exec
@@ -78,7 +78,7 @@ class DBI::DBD::Pg::Database < DBI::Base
 
         self['AutoCommit'] = true    # Postgres starts in unchained mode (AutoCommit=on) by default 
 
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::OperationalError.new(err.message)
     end
 
@@ -443,7 +443,7 @@ class DBI::DBD::Pg::Database < DBI::Base
     #
     # Create a BLOB.
     #
-    def __blob_create(mode=PGconn::INV_READ)
+    def __blob_create(mode=PG::Connection::INV_READ)
         start_transaction unless @in_transaction
         @connection.lo_creat(mode)
     rescue PGError => err
@@ -453,7 +453,7 @@ class DBI::DBD::Pg::Database < DBI::Base
     #
     # Open a BLOB.
     #
-    def __blob_open(oid, mode=PGconn::INV_READ)
+    def __blob_open(oid, mode=PG::Connection::INV_READ)
         start_transaction unless @in_transaction
         @connection.lo_open(oid.to_i, mode)
     rescue PGError => err
@@ -474,7 +474,7 @@ class DBI::DBD::Pg::Database < DBI::Base
     # Read a BLOB and return the data.
     #
     def __blob_read(oid, length)
-        blob = @connection.lo_open(oid.to_i, PGconn::INV_READ)
+        blob = @connection.lo_open(oid.to_i, PG::Connection::INV_READ)
 
         if length.nil?
             data = @connection.lo_read(blob)
@@ -485,7 +485,7 @@ class DBI::DBD::Pg::Database < DBI::Base
         # FIXME it doesn't like to close here either.
         # @connection.lo_close(blob)
         data
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::DatabaseError.new(err.message) 
     end
 
@@ -494,7 +494,7 @@ class DBI::DBD::Pg::Database < DBI::Base
     #
     def __blob_write(oid, value)
         start_transaction unless @in_transaction
-        blob = @connection.lo_open(oid.to_i, PGconn::INV_WRITE)
+        blob = @connection.lo_open(oid.to_i, PG::Connection::INV_WRITE)
         res = @connection.lo_write(blob, value)
         # FIXME not sure why PG doesn't like to close here -- seems to be
         # working but we should make sure it's not eating file descriptors
@@ -510,7 +510,7 @@ class DBI::DBD::Pg::Database < DBI::Base
     #
     def __set_notice_processor(proc)
         @connection.set_notice_processor proc
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::DatabaseError.new(err.message) 
     end
 end # Database
