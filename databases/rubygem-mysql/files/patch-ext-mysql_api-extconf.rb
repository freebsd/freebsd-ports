--- ext/mysql_api/extconf.rb.orig	2024-01-21 14:47:39 UTC
+++ ext/mysql_api/extconf.rb
@@ -76,6 +76,8 @@ IO.foreach('confout') do |l|
   next unless l =~ /errmsg\.h|mysqld_error\.h/
   fn = l.split(/\"/)[1]
   IO.foreach(fn) do |m|
+    next if m =~ /ER_UNKNOWN_ERROR_CODE/
+
     if m =~ /^#define\s+([CE]R_[0-9A-Z_]+)/ then
       error_syms << $1
     end
