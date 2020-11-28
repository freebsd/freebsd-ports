--- ext/pg_query/extconf.rb.orig	2020-11-21 10:30:23 UTC
+++ ext/pg_query/extconf.rb
@@ -3,44 +3,12 @@
 require 'mkmf'
 require 'open-uri'
 
-LIB_PG_QUERY_TAG = 'gitlab-10-1.0.3'.freeze
-
 workdir = Dir.pwd
-libdir = File.join(workdir, 'libpg_query-' + LIB_PG_QUERY_TAG)
 gemdir = File.join(__dir__, '../..')
-libfile = libdir + '/libpg_query.a'
 
-unless File.exist?("#{workdir}/libpg_query.tar.gz")
-  File.open("#{workdir}/libpg_query.tar.gz", 'wb') do |target_file|
-    open("https://gitlab.com/gitlab-org/libpg_query/-/archive/#{LIB_PG_QUERY_TAG}/libpg_query-#{LIB_PG_QUERY_TAG}.tar.gz", 'rb') do |read_file|
-      target_file.write(read_file.read)
-    end
-  end
-end
+abort "pgquery is missing" unless find_header('pg_query.h')
+abort "pgquery is missing" unless find_library('pg_query', 'pg_query_init')
 
-unless Dir.exist?(libdir)
-  system("tar -xzf #{workdir}/libpg_query.tar.gz") || raise('ERROR')
-end
-
-unless Dir.exist?(libfile)
-  # Build libpg_query (and parts of PostgreSQL)
-  system("cd #{libdir}; #{ENV['MAKE'] || (RUBY_PLATFORM =~ /bsd/ ? 'gmake' : 'make')} build")
-end
-
-# Copy test files (this intentionally overwrites existing files!)
-system("cp #{libdir}/testdata/* #{gemdir}/spec/files/")
-
 $objs = ['pg_query_ruby.o']
-
-$LOCAL_LIBS << '-lpg_query'
-$LIBPATH << libdir
-$CFLAGS << " -I #{libdir} -O3 -Wall -fno-strict-aliasing -fwrapv -g"
-
-SYMFILE = File.join(__dir__, 'pg_query_ruby.sym')
-if RUBY_PLATFORM =~ /darwin/
-  $DLDFLAGS << " -Wl,-exported_symbols_list #{SYMFILE}" unless defined?(::Rubinius)
-else
-  $DLDFLAGS << " -Wl,--retain-symbols-file=#{SYMFILE}"
-end
 
 create_makefile 'pg_query/pg_query'
