--- lib/sqlite3/driver/dl/api.rb.orig	Wed Dec 22 13:45:15 2004
+++ lib/sqlite3/driver/dl/api.rb	Sun Dec 26 06:03:27 2004
@@ -38,7 +38,7 @@
     extend ::DL::Importable
 
     library_name = case RUBY_PLATFORM.downcase
-      when /linux/
+      when /linux/, /freebsd|netbsd|openbsd|dragonfly/
         "libsqlite3.so"
       when /win32/
         "sqlite3.dll"
