--- lib/dbd/pg/type.rb.orig	2018-04-15 06:18:20 UTC
+++ lib/dbd/pg/type.rb
@@ -32,7 +32,7 @@ module DBI::DBD::Pg::Type
         # Escapes the supplied data. Has no effect on the object.
         #
         def escape_bytea(str)
-            PGconn.escape_bytea(str)
+            PG::Connection.escape_bytea(str)
         end
 
         #
@@ -62,7 +62,7 @@ module DBI::DBD::Pg::Type
             #
             # Fix this for now, but beware that we'll have to unfix this as
             # soon as they fix their end.
-            ret = PGconn.unescape_bytea(obj)
+            ret = PG::Connection.unescape_bytea(obj)
 
             # XXX 
             # String#split does not properly create a full array if the the
