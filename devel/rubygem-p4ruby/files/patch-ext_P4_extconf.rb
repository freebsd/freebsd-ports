--- ext/P4/extconf.rb.orig	2024-01-21 10:40:57 UTC
+++ ext/P4/extconf.rb
@@ -384,23 +384,8 @@ def resolve_p4api_dir
 
   # When running rake compile, use this instead of other options, I'm not sure how
   # gem/bundler options are passed through via rake
-  if ENV.has_key?('p4api_dir')
-    p4api_dir = ENV['p4api_dir']
-    dir_config('p4api', "#{p4api_dir}/include", "#{p4api_dir}/lib")
-  end
-
-  if !p4api_dir && !with_config('p4api-dir') && enable_config('p4api-download', true)
-    download_api_via_https
-    unzip_file
-    p4api_dir = downloaded_p4api_dir
-    dir_config('p4api', "#{p4api_dir}/include", "#{p4api_dir}/lib")
-  elsif with_config('p4api_dir')
-    p4api_dir = with_config('p4api-dir')
-    dir_config('p4api', "#{p4api_dir}/include", "#{p4api_dir}/lib")
-  elsif !p4api_dir
-    raise '--with-p4api-dir option has not been specified, and --disable-p4api-download is in effect'
-  end
-
+  p4api_dir = with_config('p4api-dir')
+  dir_config('supp', "#{p4api_dir}/include/perforce", "#{p4api_dir}/lib/perforce")
   p4api_dir
 end
 
@@ -455,12 +440,12 @@ def p4_platform_label
       raise 'Automatic fetching of p4api from perforce FTP is not supported on Windows'
     when /darwin19|darwin[2-9][0-9]/
       "macosx1015#{p4_cpu(:darwin)}"
-    when /darwin/      
+    when /darwin/
       "darwin90#{p4_cpu(:darwin)}"
     when /solaris/
       "solaris10#{p4_cpu(:solaris)}"
     when /linux/
-      "linux26#{p4_cpu(:linux)}"    
+      "linux26#{p4_cpu(:linux)}"
   end
 end
 
@@ -586,7 +571,7 @@ puts "$libs #{$libs}"
 puts "$libs #{$libs}"
 
 # Parse the Version file into a ruby structure
-version_info = P4ApiVersion.load(p4api_dir)
+version_info = P4ApiVersion.load("#{p4api_dir}/share/examples/p4api")
 create_p4rubyconf_header(version_info, $libs)
 
 # This will generate a standard extconf.h based on what we discover locally.
