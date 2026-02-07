--- src/mix_file.cpp.orig	2017-06-12 14:07:35 UTC
+++ src/mix_file.cpp
@@ -75,7 +75,7 @@ bool MixFile::open(const string path)
     if (fh.is_open())
         close();
     
-    fh.open(path.c_str(), fstream::in | fstream::out | fstream::binary);
+    fh.open(path.c_str(), fstream::in | fstream::binary);
     if (!fh.is_open()) {
         cout << "File " << path << " failed to open" << endl;
         return false;
