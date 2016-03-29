--- ext/P4/extconf.rb.orig	2016-03-25 23:50:09.485520000 +0000
+++ ext/P4/extconf.rb	2016-03-25 23:52:32.288698000 +0000
@@ -354,22 +354,8 @@
 
   # When running rake compile, use this instead of other options, I'm not sure how
   # gem/bundler options are passed through via rake
-  if ENV.has_key?('p4api_dir')
-    p4api_dir = ENV['p4api_dir']
-    dir_config('p4api', "#{p4api_dir}/include", "#{p4api_dir}/lib")
-  end
-
-  if !p4api_dir && !with_config('p4api-dir') && enable_config('p4api-download', true)
-    download_api_via_ftp
-    unzip_file
-    p4api_dir = downloaded_p4api_dir
-    dir_config('p4api', "#{p4api_dir}/include", "#{p4api_dir}/lib")
-  elsif with_config('p4api_dir')
-    p4api_dir = with_config('p4api-dir')
-    dir_config('p4api', "#{p4api_dir}/include", "#{p4api_dir}/lib")
-  elsif !p4api_dir
-    raise '--with-p4api-dir option has not been specified, and --disable-p4api-download is in effect'
-  end
+  p4api_dir = with_config('p4api-dir')
+  dir_config('supp', "#{p4api_dir}/include/perforce", "#{p4api_dir}/lib/perforce")
 
   p4api_dir
 end
@@ -569,7 +555,8 @@
 puts "$libs #{$libs}"
 
 # Parse the Version file into a ruby structure
-version_info = P4ApiVersion.load(p4api_dir)
+#version_info = P4ApiVersion.load(p4api_dir)
+version_info = P4ApiVersion.load("#{p4api_dir}/share/examples/p4api")
 create_p4rubyconf_header(version_info, $libs)
 
 # This will generate a standard extconf.h based on what we discover locally.
@@ -577,4 +564,4 @@
 # don't believe we need to rely on actually.
 create_header
 
-create_makefile('P4')
\ No newline at end of file
+create_makefile('P4')
