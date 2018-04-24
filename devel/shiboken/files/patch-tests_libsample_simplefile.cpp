--- tests/libsample/simplefile.cpp.orig	2018-01-31 17:26:30 UTC
+++ tests/libsample/simplefile.cpp
@@ -90,13 +90,13 @@ bool
 SimpleFile::exists() const
 {
     std::ifstream ifile(p->m_filename);
-    return ifile;
+    return static_cast<bool>(ifile);
 }
 
 bool
 SimpleFile::exists(const char* filename)
 {
     std::ifstream ifile(filename);
-    return ifile;
+    return static_cast<bool>(ifile);
 }
 
