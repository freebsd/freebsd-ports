--- lib/sqlite3/driver/dl/api.rb.orig	Thu Dec 23 19:37:37 2004
+++ lib/sqlite3/driver/dl/api.rb	Mon Jan 17 03:30:10 2005
@@ -40,7 +40,7 @@
     library_name = case RUBY_PLATFORM.downcase
       when /darwin/
         "libsqlite3.dylib"
-      when /linux/
+      when /linux/, /freebsd|netbsd|openbsd|dragonfly/
         "libsqlite3.so"
       when /win32/
         "sqlite3.dll"
