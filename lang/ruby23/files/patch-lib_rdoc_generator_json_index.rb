--- ./lib/rdoc/generator/json_index.rb.orig	2017-11-12 19:38:46.598341000 -0500
+++ ./lib/rdoc/generator/json_index.rb	2017-11-12 19:38:59.759125000 -0500
@@ -175,7 +175,7 @@
     debug_msg "Writing gzipped search index to %s" % outfile
 
     Zlib::GzipWriter.open(outfile) do |gz|
-      gz.mtime = File.mtime(search_index_file)
+      gz.mtime = 1
       gz.orig_name = search_index_file.basename.to_s
       gz.write search_index
       gz.close
@@ -193,7 +193,7 @@
         debug_msg "Writing gzipped file to %s" % outfile
 
         Zlib::GzipWriter.open(outfile) do |gz|
-          gz.mtime = File.mtime(dest)
+          gz.mtime = 1
           gz.orig_name = dest.basename.to_s
           gz.write data
           gz.close
