--- include/jellyfish/dumper.hpp.orig	2021-09-11 12:09:13 UTC
+++ include/jellyfish/dumper.hpp
@@ -54,7 +54,7 @@ class dumper_t { (protected)
     }
     file_names_.push_back(name.str());
 
-    out.open(name.str().c_str());
+    out.open(name.str().c_str(), mode);
     if(out.fail())
       throw ErrorWriting(err::msg() << "'" << name.str() << "': "
                          << "Can't open file for writing" << err::no);
