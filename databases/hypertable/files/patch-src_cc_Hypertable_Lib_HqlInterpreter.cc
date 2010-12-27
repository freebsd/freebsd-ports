--- src/cc/Hypertable/Lib/HqlInterpreter.cc.orig	2010-12-13 17:56:18.000000000 +0300
+++ src/cc/Hypertable/Lib/HqlInterpreter.cc	2010-12-13 17:55:27.000000000 +0300
@@ -272,7 +272,7 @@
   }
   else {
     out_fd = dup(fileno(outf));
-    fout.push(boost::iostreams::file_descriptor_sink(out_fd));
+    fout.push(boost::iostreams::file_descriptor_sink(out_fd, boost::iostreams::never_close_handle));
   }
 
   HT_ON_SCOPE_EXIT(&close_file, out_fd);
@@ -397,7 +397,7 @@
   }
   else {
     out_fd = dup(fileno(outf));
-    fout.push(boost::iostreams::file_descriptor_sink(out_fd));
+    fout.push(boost::iostreams::file_descriptor_sink(out_fd, boost::iostreams::never_close_handle));
   }
 
   HT_ON_SCOPE_EXIT(&close_file, out_fd);
@@ -488,7 +488,7 @@
   else {
     if (outf) {
       out_fd = dup(fileno(outf));
-      fout.push(boost::iostreams::file_descriptor_sink(out_fd));
+      fout.push(boost::iostreams::file_descriptor_sink(out_fd, boost::iostreams::never_close_handle));
     }
     else
       fout.push(boost::iostreams::null_sink());
