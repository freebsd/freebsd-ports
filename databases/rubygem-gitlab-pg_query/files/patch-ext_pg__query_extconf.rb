--- ext/pg_query/extconf.rb.orig	2020-11-20 23:41:38 UTC
+++ ext/pg_query/extconf.rb
@@ -10,22 +10,22 @@ libdir = File.join(workdir, 'libpg_query-' + LIB_PG_QU
 gemdir = File.join(__dir__, '../..')
 libfile = libdir + '/libpg_query.a'
 
-unless File.exist?("#{workdir}/libpg_query.tar.gz")
-  File.open("#{workdir}/libpg_query.tar.gz", 'wb') do |target_file|
-    open("https://gitlab.com/gitlab-org/libpg_query/-/archive/#{LIB_PG_QUERY_TAG}/libpg_query-#{LIB_PG_QUERY_TAG}.tar.gz", 'rb') do |read_file|
-      target_file.write(read_file.read)
-    end
-  end
-end
+#unless File.exist?("#{workdir}/libpg_query.tar.gz")
+#  File.open("#{workdir}/libpg_query.tar.gz", 'wb') do |target_file|
+#    open("https://gitlab.com/gitlab-org/libpg_query/-/archive/#{LIB_PG_QUERY_TAG}/libpg_query-#{LIB_PG_QUERY_TAG}.tar.gz", 'rb') do |read_file|
+#      target_file.write(read_file.read)
+#    end
+#  end
+#end
 
-unless Dir.exist?(libdir)
-  system("tar -xzf #{workdir}/libpg_query.tar.gz") || raise('ERROR')
-end
+#unless Dir.exist?(libdir)
+#  system("tar -xzf #{workdir}/libpg_query.tar.gz") || raise('ERROR')
+#end
 
-unless Dir.exist?(libfile)
-  # Build libpg_query (and parts of PostgreSQL)
-  system("cd #{libdir}; #{ENV['MAKE'] || (RUBY_PLATFORM =~ /bsd/ ? 'gmake' : 'make')} build")
-end
+#unless Dir.exist?(libfile)
+#  # Build libpg_query (and parts of PostgreSQL)
+#  system("cd #{libdir}; #{ENV['MAKE'] || (RUBY_PLATFORM =~ /bsd/ ? 'gmake' : 'make')} build")
+#end
 
 # Copy test files (this intentionally overwrites existing files!)
 system("cp #{libdir}/testdata/* #{gemdir}/spec/files/")
