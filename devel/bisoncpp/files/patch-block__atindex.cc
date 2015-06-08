--- block/atindex.cc.orig	2013-06-23 18:13:49 UTC
+++ block/atindex.cc
@@ -6,7 +6,7 @@ void Block::atIndex(size_t lineNr, strin
     d_atDollar.push_back(
         AtDollar(
             AtDollar::AT, length(), lineNr, 
-            text, stol(text.substr(1)), false
+            text, A2x(text.substr(1)), false
         )
     );
     append(text);
