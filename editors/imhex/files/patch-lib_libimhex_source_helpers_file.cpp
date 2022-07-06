--- lib/libimhex/source/helpers/file.cpp.orig	2022-07-04 19:53:18 UTC
+++ lib/libimhex/source/helpers/file.cpp
@@ -16,12 +16,12 @@ namespace hex::fs {
                 this->m_file = _wfopen(path.c_str(), L"w+b");
         #else
             if (mode == File::Mode::Read)
-                this->m_file = fopen64(path.string().c_str(), "rb");
+                this->m_file = fopen(path.string().c_str(), "rb");
             else if (mode == File::Mode::Write)
-                this->m_file = fopen64(path.string().c_str(), "r+b");
+                this->m_file = fopen(path.string().c_str(), "r+b");
 
             if (mode == File::Mode::Create || (mode == File::Mode::Write && this->m_file == nullptr))
-                this->m_file = fopen64(path.string().c_str(), "w+b");
+                this->m_file = fopen(path.string().c_str(), "w+b");
         #endif
     }
 
@@ -49,7 +49,7 @@ namespace hex::fs {
 
 
     void File::seek(u64 offset) {
-        fseeko64(this->m_file, offset, SEEK_SET);
+        fseeko(this->m_file, offset, SEEK_SET);
     }
 
     void File::close() {
@@ -134,10 +134,10 @@ namespace hex::fs {
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
@@ -148,7 +148,7 @@ namespace hex::fs {
     void File::setSize(u64 size) {
         if (!isValid()) return;
 
-        auto result = ftruncate64(fileno(this->m_file), size);
+        auto result = ftruncate(fileno(this->m_file), size);
         hex::unused(result);
     }
 
