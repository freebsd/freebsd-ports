--- ext/pg_query/extconf.rb.orig	2021-01-21 21:10:31 UTC
+++ ext/pg_query/extconf.rb
@@ -4,52 +4,9 @@ require 'digest'
 require 'mkmf'
 require 'open-uri'
 
-LIB_PG_QUERY_TAG = '10-1.0.4'.freeze
-LIB_PG_QUERY_SHA256SUM = '88cc90296e5fcaaebd0b360c46698b7c5badddf86f120e249ef682a820d41338'.freeze
-
 workdir = Dir.pwd
-libdir = File.join(workdir, 'libpg_query-' + LIB_PG_QUERY_TAG)
 gemdir = File.join(__dir__, '../..')
-libfile = libdir + '/libpg_query.a'
-filename = File.join(workdir, 'libpg_query-' + LIB_PG_QUERY_TAG + '.tar.gz')
 
-unless File.exist?(filename)
-  File.open(filename, 'wb') do |target_file|
-    URI.open('https://codeload.github.com/lfittl/libpg_query/tar.gz/' + LIB_PG_QUERY_TAG, 'rb') do |read_file|
-      target_file.write(read_file.read)
-    end
-  end
-
-  checksum = Digest::SHA256.hexdigest(File.read(filename))
-
-  if checksum != LIB_PG_QUERY_SHA256SUM
-    raise "SHA256 of #{filename} does not match: got #{checksum}, expected #{expected_sha256}"
-  end
-end
-
-unless Dir.exist?(libdir)
-  system("tar -xzf #{filename}") || raise('ERROR')
-end
-
-unless Dir.exist?(libfile)
-  # Build libpg_query (and parts of PostgreSQL)
-  system(format("cd %s; %s build", libdir, ENV['MAKE'] || (RUBY_PLATFORM =~ /bsd/ ? 'gmake' : 'make')))
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
