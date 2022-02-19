--- lib/libimhex/source/helpers/file.cpp.orig	2022-02-15 12:57:57 UTC
+++ lib/libimhex/source/helpers/file.cpp
@@ -5,12 +5,12 @@ namespace hex {
 
     File::File(const fs::path &path, Mode mode) noexcept : m_path(path) {
         if (mode == File::Mode::Read)
-            this->m_file = fopen64(path.string().c_str(), "rb");
+            this->m_file = fopen(path.string().c_str(), "rb");
         else if (mode == File::Mode::Write)
-            this->m_file = fopen64(path.string().c_str(), "r+b");
+            this->m_file = fopen(path.string().c_str(), "r+b");
 
         if (mode == File::Mode::Create || (mode == File::Mode::Write && this->m_file == nullptr))
-            this->m_file = fopen64(path.string().c_str(), "w+b");
+            this->m_file = fopen(path.string().c_str(), "w+b");
     }
 
     File::File() noexcept {
@@ -37,7 +37,7 @@ namespace hex {
 
 
     void File::seek(u64 offset) {
-        fseeko64(this->m_file, offset, SEEK_SET);
+        fseeko(this->m_file, offset, SEEK_SET);
     }
 
     void File::close() {
@@ -96,10 +96,10 @@ namespace hex {
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
@@ -107,7 +107,7 @@ namespace hex {
     void File::setSize(u64 size) {
         if (!isValid()) return;
 
-        ftruncate64(fileno(this->m_file), size);
+        ftruncate(fileno(this->m_file), size);
     }
 
     void File::flush() {
