--- lib/external/pattern_language/lib/source/pl/helpers/file.cpp.orig	2022-08-14 15:37:26 UTC
+++ lib/external/pattern_language/lib/source/pl/helpers/file.cpp
@@ -19,12 +19,12 @@ namespace pl::hlp::fs {
                 this->m_file = _wfopen(path.c_str(), L"w+b");
         #else
             if (mode == File::Mode::Read)
-                    this->m_file = fopen64(path.string().c_str(), "rb");
+                    this->m_file = fopen(path.string().c_str(), "rb");
                 else if (mode == File::Mode::Write)
-                    this->m_file = fopen64(path.string().c_str(), "r+b");
+                    this->m_file = fopen(path.string().c_str(), "r+b");
 
                 if (mode == File::Mode::Create || (mode == File::Mode::Write && this->m_file == nullptr))
-                    this->m_file = fopen64(path.string().c_str(), "w+b");
+                    this->m_file = fopen(path.string().c_str(), "w+b");
         #endif
     }
 
@@ -52,7 +52,7 @@ namespace pl::hlp::fs {
 
 
     void File::seek(u64 offset) {
-        fseeko64(this->m_file, offset, SEEK_SET);
+        fseeko(this->m_file, offset, SEEK_SET);
     }
 
     void File::close() {
@@ -137,10 +137,10 @@ namespace pl::hlp::fs {
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
@@ -151,7 +151,7 @@ namespace pl::hlp::fs {
     void File::setSize(u64 size) {
         if (!isValid()) return;
 
-        auto result = ftruncate64(fileno(this->m_file), size);
+        auto result = ftruncate(fileno(this->m_file), size);
         hlp::unused(result);
     }
 
