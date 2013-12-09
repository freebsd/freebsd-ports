--- src/libirc/Parser.cpp.orig	Sat May 31 09:25:44 2003
+++ src/libirc/Parser.cpp	Mon Jul  7 00:37:53 2003
@@ -681,7 +681,7 @@
     ss >> time;
 
     long date = std::atol(time.c_str());
-    time = std::ctime(&date);
+    time = std::ctime((const time_t *)&date);
 
     Channel *c = _conn->findChannel(chan);
     assert(c);
