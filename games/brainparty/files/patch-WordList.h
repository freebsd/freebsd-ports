--- WordList.h.orig	2010-03-02 16:29:45.000000000 +0300
+++ WordList.h	2013-09-13 05:51:27.977229632 +0400
@@ -35,7 +35,7 @@
 	};
 }
 
-typedef hash_set<string, hash<string> > string_hash_set;
+typedef hash_set<string, __gnu_cxx::hash<string> > string_hash_set;
 
 class WordList {
 private:
