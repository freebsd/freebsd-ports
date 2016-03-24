--- include/jellyfish/file_header.hpp.orig	2015-10-27 14:32:31 UTC
+++ include/jellyfish/file_header.hpp
@@ -21,6 +21,8 @@
 #include <jellyfish/generic_file_header.hpp>
 #include <jellyfish/rectangular_binary_matrix.hpp>
 
+using std::string;
+
 namespace jellyfish {
 /// A header with jellyfish hash specific entries: size, matrix, etc.
 class file_header : public generic_file_header {
@@ -42,7 +44,10 @@ public:
 
   RectangularBinaryMatrix matrix(int i = 1) const {
     std::string name("matrix");
-    name += std::to_string((long long int)i); // Cast to make gcc4.4 happy!
+    char   buff[100];
+    // name += std::to_string((long long int)i); // Cast to make gcc4.4 happy!
+    snprintf(buff, 99, "%d", i);
+    name += buff;
     const unsigned int r = root_[name]["r"].asUInt();
     const unsigned int c = root_[name]["c"].asUInt();
     std::vector<uint64_t> raw(c, (uint64_t)0);
@@ -53,7 +58,10 @@ public:
 
   void matrix(const RectangularBinaryMatrix& m, int i = 1) {
     std::string name("matrix");
-    name += std::to_string((long long int)i);
+    char   buff[100];
+    // name += std::to_string((long long int)i);
+    snprintf(buff, 99, "%d", i);
+    name += buff;
     root_[name].clear();
     root_[name]["r"] = m.r();
     root_[name]["c"] = m.c();
