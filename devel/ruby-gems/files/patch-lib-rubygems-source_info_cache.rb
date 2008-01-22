--- lib/rubygems/source_info_cache.rb.orig	2007-12-11 09:16:59.000000000 +0800
+++ lib/rubygems/source_info_cache.rb	2007-12-26 17:24:45.000000000 +0800
@@ -70,6 +70,9 @@
     begin
       # Marshal loads 30-40% faster from a String, and 2MB on 20061116 is small
       data = File.open cache_file, 'rb' do |fp| fp.read end
+      if data.length <= 4 then
+        raise ArgumentError, "Data too small"
+      end
       @cache_data = Marshal.load data
 
       @cache_data.each do |url, sice|
@@ -85,11 +88,11 @@
         end
       end
       @cache_data
-    rescue => e
+    rescue => ex
       if Gem.configuration.really_verbose then
         say "Exception during cache_data handling: #{ex.class} - #{ex}"
         say "Cache file was: #{cache_file}"
-        say "\t#{e.backtrace.join "\n\t"}"
+        say "\t#{ex.backtrace.join "\n\t"}"
       end
       reset_cache_data
     end
@@ -107,6 +110,7 @@
 
   def reset_cache_data
+    FileUtils.rm @cache_file
     @cache_data = {}
   end
 
   # The name of the cache file to be read
