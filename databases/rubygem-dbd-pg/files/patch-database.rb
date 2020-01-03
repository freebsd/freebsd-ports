--- lib/dbd/pg/database.rb.orig	2020-01-03 12:38:44 UTC
+++ lib/dbd/pg/database.rb
@@ -48,7 +48,7 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
         hash['tty'] ||= ''
         hash['port'] = hash['port'].to_i unless hash['port'].nil? 
 
-        @connection = PGconn.new(hash['host'], hash['port'], hash['options'], hash['tty'], 
+        @connection = PG::Connection.new(hash['host'], hash['port'], hash['options'], hash['tty'], 
                                  hash['dbname'] || hash['database'], user, auth)
 
         @exec_method = :exec
@@ -78,7 +78,7 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
 
         self['AutoCommit'] = true    # Postgres starts in unchained mode (AutoCommit=on) by default 
 
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::OperationalError.new(err.message)
     end
 
@@ -96,7 +96,7 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
         else
             return false
         end
-    rescue PGError
+    rescue PG::Error
         return false
     ensure
         answer.clear if answer
@@ -383,9 +383,6 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
                         end
                 }
         end 
-        # additional conversions
-        @type_map[705]  ||= DBI::Type::Varchar       # select 'hallo'
-        @type_map[1114] ||= DBI::Type::Timestamp # TIMESTAMP WITHOUT TIME ZONE
 
         # remap array subtypes
         @type_map.each_key do |key|
@@ -399,6 +396,10 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
                 end
             end
         end
+
+        # additional conversions
+        @type_map[1114] ||= DBI::Type::Timestamp # TIMESTAMP WITHOUT TIME ZONE
+        @type_map[705]  ||= DBI::Type::Varchar       # select 'hallo'
     end
 
     public
@@ -426,7 +427,7 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
     def __blob_import(file)
         start_transaction unless @in_transaction
         @connection.lo_import(file)
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::DatabaseError.new(err.message) 
     end
 
@@ -436,27 +437,27 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
     def __blob_export(oid, file)
         start_transaction unless @in_transaction
         @connection.lo_export(oid.to_i, file)
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::DatabaseError.new(err.message) 
     end
 
     #
     # Create a BLOB.
     #
-    def __blob_create(mode=PGconn::INV_READ)
+    def __blob_create(mode=PG::Connection::INV_READ)
         start_transaction unless @in_transaction
         @connection.lo_creat(mode)
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::DatabaseError.new(err.message) 
     end
 
     #
     # Open a BLOB.
     #
-    def __blob_open(oid, mode=PGconn::INV_READ)
+    def __blob_open(oid, mode=PG::Connection::INV_READ)
         start_transaction unless @in_transaction
         @connection.lo_open(oid.to_i, mode)
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::DatabaseError.new(err.message) 
     end
 
@@ -466,7 +467,7 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
     def __blob_unlink(oid)
         start_transaction unless @in_transaction
         @connection.lo_unlink(oid.to_i)
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::DatabaseError.new(err.message) 
     end
 
@@ -474,7 +475,7 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
     # Read a BLOB and return the data.
     #
     def __blob_read(oid, length)
-        blob = @connection.lo_open(oid.to_i, PGconn::INV_READ)
+        blob = @connection.lo_open(oid.to_i, PG::Connection::INV_READ)
 
         if length.nil?
             data = @connection.lo_read(blob)
@@ -485,7 +486,7 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
         # FIXME it doesn't like to close here either.
         # @connection.lo_close(blob)
         data
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::DatabaseError.new(err.message) 
     end
 
@@ -494,14 +495,14 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
     #
     def __blob_write(oid, value)
         start_transaction unless @in_transaction
-        blob = @connection.lo_open(oid.to_i, PGconn::INV_WRITE)
+        blob = @connection.lo_open(oid.to_i, PG::Connection::INV_WRITE)
         res = @connection.lo_write(blob, value)
         # FIXME not sure why PG doesn't like to close here -- seems to be
         # working but we should make sure it's not eating file descriptors
         # up before release.
         # @connection.lo_close(blob)
         return res
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::DatabaseError.new(err.message)
     end
 
@@ -510,7 +511,7 @@ class DBI::DBD::Pg::Database < DBI::BaseDatabase
     #
     def __set_notice_processor(proc)
         @connection.set_notice_processor proc
-    rescue PGError => err
+    rescue PG::Error => err
         raise DBI::DatabaseError.new(err.message) 
     end
 end # Database
