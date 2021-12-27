--- plugins/libimhex/source/helpers/file.cpp.orig	2021-11-28 20:34:17 UTC
+++ plugins/libimhex/source/helpers/file.cpp
@@ -5,12 +5,12 @@ namespace hex {
 
     File::File(const std::string &path, Mode mode) : m_path(path) {
         if (mode == File::Mode::Read)
-            this->m_file = fopen64(path.c_str(), "rb");
+            this->m_file = fopen(path.c_str(), "rb");
         else if (mode == File::Mode::Write)
-            this->m_file = fopen64(path.c_str(), "r+b");
+            this->m_file = fopen(path.c_str(), "r+b");
 
         if (mode == File::Mode::Create || (mode == File::Mode::Write && this->m_file == nullptr))
-            this->m_file = fopen64(path.c_str(), "w+b");
+            this->m_file = fopen(path.c_str(), "w+b");
     }
 
     File::File() {
@@ -27,7 +27,7 @@ namespace hex {
     }
 
     void File::seek(u64 offset) {
-        fseeko64(this->m_file, offset, SEEK_SET);
+        fseeko(this->m_file, offset, SEEK_SET);
     }
 
     void File::close() {
@@ -85,10 +85,10 @@ namespace hex {
     size_t File::getSize() const {
         if (!isValid()) return 0;
 
-        auto startPos = ftello64(this->m_file);
-        fseeko64(this->m_file, 0, SEEK_END);
-        size_t size = ftello64(this->m_file);
-        fseeko64(this->m_file, startPos, SEEK_SET);
+        auto startPos = ftello(this->m_file);
+        fseeko(this->m_file, 0, SEEK_END);
+        size_t size = ftello(this->m_file);
+        fseeko(this->m_file, startPos, SEEK_SET);
 
         return size;
     }
@@ -96,7 +96,7 @@ namespace hex {
     void File::setSize(u64 size) {
         if (!isValid()) return;
 
-        ftruncate64(fileno(this->m_file), size);
+        ftruncate(fileno(this->m_file), size);
     }
 
     void File::flush() {
