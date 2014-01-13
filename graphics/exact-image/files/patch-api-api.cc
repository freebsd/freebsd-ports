--- api/api.cc.orig	2009-06-15 14:39:45.000000000 +0400
+++ api/api.cc	2014-01-13 07:25:57.460488862 +0400
@@ -909,7 +909,7 @@
   }
   
   std::vector<std::string> ret;
-  for (std::map<scanner_result_t,int>::const_iterator it = retcodes.begin();
+  for (std::map<scanner_result_t,int,comp>::const_iterator it = retcodes.begin();
        it != retcodes.end();
        ++it) {
     if (it->first.type || it->second > 1)
