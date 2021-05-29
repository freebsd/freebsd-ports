--- ext/pg_query/extconf.rb.orig	2021-05-19 21:51:31 UTC
+++ ext/pg_query/extconf.rb
@@ -7,13 +7,6 @@ require 'pathname'
 
 $objs = Dir.glob(File.join(__dir__, '*.c')).map { |f| Pathname.new(f).sub_ext('.o').to_s }
 
-$CFLAGS << " -I#{File.join(__dir__, 'include')} -O3 -Wall -fno-strict-aliasing -fwrapv -fstack-protector -Wno-unused-function -Wno-unused-variable -g"
-
-SYMFILE = File.join(__dir__, 'pg_query_ruby.sym')
-if RUBY_PLATFORM =~ /darwin/
-  $DLDFLAGS << " -Wl,-exported_symbols_list #{SYMFILE}" unless defined?(::Rubinius)
-else
-  $DLDFLAGS << " -Wl,--retain-symbols-file=#{SYMFILE}"
-end
+$CFLAGS << " -I#{File.join(__dir__, 'include')} -O3 -Wall -fno-strict-aliasing -fwrapv -fstack-protector -Wno-unused-function -Wno-unused-variable -DHAVE_STRCHRNUL -g"
 
 create_makefile 'pg_query/pg_query'
