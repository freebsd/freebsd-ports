--- lib/external/pattern_language/lib/source/helpers/file.cpp.orig	2022-05-04 11:27:58 UTC
+++ lib/external/pattern_language/lib/source/helpers/file.cpp
@@ -7,12 +7,12 @@ namespace pl::fs {
 
     File::File(const std::fs::path &path, Mode mode) noexcept : m_path(path) {
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
@@ -39,7 +39,7 @@ namespace pl::fs {
 
 
     void File::seek(u64 offset) {
-        fseeko64(this->m_file, offset, SEEK_SET);
+        fseeko(this->m_file, offset, SEEK_SET);
     }
 
     void File::close() {
@@ -103,10 +103,10 @@ namespace pl::fs {
     size_t File::getSize() const {
         if (!isValid()) return 0;
 
-        auto startPos = ftello64(this->m_file);
-        fseeko64(this->m_file, 0, SEEK_END);
-        auto size = ftello64(this->m_file);
-        fseeko64(this->m_file, startPos, SEEK_SET);
+        auto startPos = ftello(this->m_file);
+        fseeko(this->m_file, 0, SEEK_END);
+        auto size = ftello(this->m_file);
+        fseeko(this->m_file, startPos, SEEK_SET);
 
         if (size < 0)
             return 0;
@@ -117,7 +117,7 @@ namespace pl::fs {
     void File::setSize(u64 size) {
         if (!isValid()) return;
 
-        auto result = ftruncate64(fileno(this->m_file), size);
+        auto result = ftruncate(fileno(this->m_file), size);
         pl::unused(result);
     }
 
