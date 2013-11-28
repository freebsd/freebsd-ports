--- ./block/idindex.cc.orig	2013-06-23 20:13:49.000000000 +0200
+++ ./block/idindex.cc	2013-11-27 18:54:04.000000000 +0100
@@ -8,7 +8,7 @@
     d_atDollar.push_back(
         AtDollar(
             AtDollar::DOLLAR, length(), lineNr, 
-            text, text.substr(begin, end - begin), stol(text.substr(end + 1))
+            text, text.substr(begin, end - begin), A2x(text.substr(end + 1))
         )
     );
 
