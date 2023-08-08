--- lib/rdoc/generator/json_index.rb.orig	2023-05-12 09:25:10 UTC
+++ lib/rdoc/generator/json_index.rb
@@ -178,7 +178,7 @@ class RDoc::Generator::JsonIndex
     debug_msg "Writing gzipped search index to %s" % outfile
 
     Zlib::GzipWriter.open(outfile) do |gz|
-      gz.mtime = File.mtime(search_index_file)
+      gz.mtime = 1
       gz.orig_name = search_index_file.basename.to_s
       gz.write search_index
       gz.close
@@ -196,7 +196,7 @@ class RDoc::Generator::JsonIndex
         debug_msg "Writing gzipped file to %s" % outfile
 
         Zlib::GzipWriter.open(outfile) do |gz|
-          gz.mtime = File.mtime(dest)
+          gz.mtime = 1
           gz.orig_name = dest.basename.to_s
           gz.write data
           gz.close
