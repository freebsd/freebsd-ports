--- lib/external/libwolv/libs/io/source/io/file.cpp.orig	2023-07-09 11:32:49 UTC
+++ lib/external/libwolv/libs/io/source/io/file.cpp
@@ -39,12 +39,12 @@ namespace wolv::io {
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
 
@@ -82,7 +82,7 @@ namespace wolv::io {
     }
 
     void File::seek(u64 offset) {
-        fseeko64(this->m_file, offset, SEEK_SET);
+        fseeko(this->m_file, offset, SEEK_SET);
     }
 
     void File::close() {
@@ -114,8 +114,7 @@ namespace wolv::io {
             auto fd = fileno(this->m_file);
             auto size = getSize();
 
-            this->m_map = reinterpret_cast<u8*>(mmap(nullptr, size, this->m_mode == Mode::Read ? PROT_READ : PROT_WRITE, MAP_SHARED, fd, 0));
-
+            this->m_map = reinterpret_cast<u8*>(mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
         #endif
     }
 
@@ -214,7 +213,7 @@ namespace wolv::io {
     void File::setSize(u64 size) {
         if (!isValid()) return;
 
-        auto result = ftruncate64(fileno(this->m_file), size);
+        auto result = ftruncate(fileno(this->m_file), size);
         util::unused(result);
         this->updateSize();
     }
@@ -225,10 +224,10 @@ namespace wolv::io {
             return;
         }
 
-        auto startPos = ftello64(this->m_file);
-        fseeko64(this->m_file, 0, SEEK_END);
-        auto size = ftello64(this->m_file);
-        fseeko64(this->m_file, startPos, SEEK_SET);
+        auto startPos = ftello(this->m_file);
+        fseeko(this->m_file, 0, SEEK_END);
+        auto size = ftello(this->m_file);
+        fseeko(this->m_file, startPos, SEEK_SET);
 
         if (this->m_map != nullptr && size != this->m_fileSize) {
             this->unmap();
