--- block/idindex.cc.orig	2013-06-23 18:13:49 UTC
+++ block/idindex.cc
@@ -8,7 +8,7 @@ void Block::IDindex(size_t lineNr, strin
     d_atDollar.push_back(
         AtDollar(
             AtDollar::DOLLAR, length(), lineNr, 
-            text, text.substr(begin, end - begin), stol(text.substr(end + 1))
+            text, text.substr(begin, end - begin), A2x(text.substr(end + 1))
         )
     );
 
