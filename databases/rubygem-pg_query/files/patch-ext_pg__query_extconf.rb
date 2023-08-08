--- ext/pg_query/extconf.rb.orig	2023-06-25 07:15:18 UTC
+++ ext/pg_query/extconf.rb
@@ -12,11 +12,7 @@ $CFLAGS << " -fvisibility=hidden -O3 -Wall -fno-strict
 $INCFLAGS = "-I#{File.join(__dir__, 'include')} " + $INCFLAGS
 
 SYMFILE =
-  if RUBY_PLATFORM =~ /freebsd/
-    File.join(__dir__, 'pg_query_ruby_freebsd.sym')
-  else
     File.join(__dir__, 'pg_query_ruby.sym')
-  end
 
 if RUBY_PLATFORM =~ /darwin/
   $DLDFLAGS << " -Wl,-exported_symbols_list #{SYMFILE}" unless defined?(::Rubinius)
