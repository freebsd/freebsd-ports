--- lib/external/libwolv/libs/io/source/io/file.cpp.orig	2023-04-08 15:55:46 UTC
+++ lib/external/libwolv/libs/io/source/io/file.cpp
@@ -21,12 +21,12 @@ namespace wolv::io {
         #else
 
             if (mode == File::Mode::Read)
-                this->m_file = fopen64(util::toUTF8String(path).c_str(), "rb");
+                this->m_file = fopen(util::toUTF8String(path).c_str(), "rb");
             else if (mode == File::Mode::Write)
-                this->m_file = fopen64(util::toUTF8String(path).c_str(), "r+b");
+                this->m_file = fopen(util::toUTF8String(path).c_str(), "r+b");
 
             if (mode == File::Mode::Create || (mode == File::Mode::Write && this->m_file == nullptr))
-                this->m_file = fopen64(util::toUTF8String(path).c_str(), "w+b");
+                this->m_file = fopen(util::toUTF8String(path).c_str(), "w+b");
 
         #endif
     }
@@ -63,7 +63,7 @@ namespace wolv::io {
     }
 
     void File::seek(u64 offset) {
-        fseeko64(this->m_file, offset, SEEK_SET);
+        fseeko(this->m_file, offset, SEEK_SET);
     }
 
     void File::close() {
@@ -148,10 +148,10 @@ namespace wolv::io {
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
@@ -162,7 +162,7 @@ namespace wolv::io {
     void File::setSize(u64 size) {
         if (!isValid()) return;
 
-        auto result = ftruncate64(fileno(this->m_file), size);
+        auto result = ftruncate(fileno(this->m_file), size);
         util::unused(result);
     }
 
