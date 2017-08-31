--- extconf.rb.orig	2017-08-31 10:56:23 UTC
+++ extconf.rb
@@ -122,6 +122,8 @@ end
 case version_str = `#{pg_config} --version`
 when /^PostgreSQL ([7-9])\.([0-9]{1,3})(\.[0-9]{1,3})?$/
    version = 10 * $1.to_i + $2.to_i
+when /^PostgreSQL 10/
+   version = 100
 else
    version = 0
 end
