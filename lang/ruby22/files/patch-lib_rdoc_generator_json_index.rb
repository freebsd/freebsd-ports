--- ./lib/rdoc/generator/json_index.rb.orig	2017-11-12 19:41:46.332613000 -0500
+++ ./lib/rdoc/generator/json_index.rb	2017-11-12 19:41:56.834004000 -0500
@@ -169,7 +169,7 @@
     debug_msg "Writing gzipped search index to %s" % outfile
 
     Zlib::GzipWriter.open(outfile) do |gz|
-      gz.mtime = File.mtime(search_index_file)
+      gz.mtime = 1
       gz.orig_name = search_index_file.to_s
       gz.write search_index
       gz.close
@@ -187,7 +187,7 @@
         debug_msg "Writing gzipped file to %s" % outfile
 
         Zlib::GzipWriter.open(outfile) do |gz|
-          gz.mtime = File.mtime(dest)
+          gz.mtime = 1
           gz.orig_name = dest.to_s
           gz.write data
           gz.close
