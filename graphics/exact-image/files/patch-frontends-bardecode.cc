--- frontends/bardecode.cc.orig	2010-06-18 18:02:15.000000000 +0400
+++ frontends/bardecode.cc	2014-01-13 07:31:33.549465639 +0400
@@ -145,7 +145,7 @@
           }
       }
       
-      for (std::map<scanner_result_t,int>::const_iterator it = codes.begin();
+      for (std::map<scanner_result_t,int,comp>::const_iterator it = codes.begin();
 	   it != codes.end();
 	   ++it) {
 	if (it->first.type&(ean|code128|gs1_128) || it->second > 1)
