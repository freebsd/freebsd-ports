--- extconf.rb.orig	2017-05-28 08:47:01 UTC
+++ extconf.rb
@@ -122,6 +122,10 @@ end
 case version_str = `#{pg_config} --version`
 when /^PostgreSQL ([7-9])\.([0-9]{1,3})(\.[0-9]{1,3})?$/
    version = 10 * $1.to_i + $2.to_i
+when /^PostgreSQL 11/
+   version = 110
+when /^PostgreSQL 10/
+   version = 100
 else
    version = 0
 end
