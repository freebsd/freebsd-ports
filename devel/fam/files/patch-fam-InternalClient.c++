diff -ruN fam/InternalClient.c++ fam/InternalClient.c++
--- fam/InternalClient.c++	Mon Apr 29 02:26:54 2002
+++ fam/InternalClient.c++	Sat Jun  8 16:31:07 2002
@@ -35,8 +35,8 @@
 {
     assert(filename);
     assert(h);
-    assert(filename[0] == '/');
     Log::debug("%s watching %s", name(), filename);
+    assert(filename[0] == '/');
     interest = new File(filename, this, Request(0), Cred::SuperUser);
 }
 
