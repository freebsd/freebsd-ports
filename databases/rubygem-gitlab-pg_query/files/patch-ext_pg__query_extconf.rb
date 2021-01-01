--- ext/pg_query/extconf.rb.orig	2021-01-01 08:22:43 UTC
+++ ext/pg_query/extconf.rb
@@ -4,53 +4,9 @@ require 'digest'
 require 'mkmf'
 require 'open-uri'
 
-LIB_PG_QUERY_TAG = '10-1.0.3'.freeze
-
 workdir = Dir.pwd
-libdir = File.join(workdir, 'libpg_query-' + LIB_PG_QUERY_TAG)
 gemdir = File.join(__dir__, '../..')
-libfile = libdir + '/libpg_query.a'
 
-expected_sha256 = '1332761f31c198cb9825e6ccccda0b6a0e57daeb824870e8524df77f1592d149'
-filename = "#{workdir}/libpg_query.tar.gz"
-
-unless File.exist?(filename)
-  File.open(filename, 'wb') do |target_file|
-    URI.open('https://codeload.github.com/lfittl/libpg_query/tar.gz/' + LIB_PG_QUERY_TAG, 'rb') do |read_file|
-      target_file.write(read_file.read)
-    end
-  end
-
-  checksum = Digest::SHA256.hexdigest(File.read(filename))
-
-  if checksum != expected_sha256
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
