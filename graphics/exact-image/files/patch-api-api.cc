--- api/api.cc.orig	2009-06-15 10:39:45 UTC
+++ api/api.cc
@@ -909,7 +909,7 @@ char** imageDecodeBarcodes (Image* image, const char* 
   }
   
   std::vector<std::string> ret;
-  for (std::map<scanner_result_t,int>::const_iterator it = retcodes.begin();
+  for (std::map<scanner_result_t,int,comp>::const_iterator it = retcodes.begin();
        it != retcodes.end();
        ++it) {
     if (it->first.type || it->second > 1)
