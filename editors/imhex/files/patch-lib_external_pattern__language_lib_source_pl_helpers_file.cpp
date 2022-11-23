--- lib/external/pattern_language/lib/source/pl/helpers/file.cpp.orig	2022-11-16 14:22:38 UTC
+++ lib/external/pattern_language/lib/source/pl/helpers/file.cpp
@@ -8,7 +8,7 @@
 
 namespace pl::hlp::fs {
 
-#if defined(OS_MACOS)
+#if defined(OS_MACOS) || defined(__FreeBSD__)
     #define fopen64 fopen
     #define ftruncate64 ftruncate
 #endif
@@ -57,7 +57,7 @@ namespace pl::hlp::fs {
 
 
     void File::seek(u64 offset) {
-        fseeko64(this->m_file, offset, SEEK_SET);
+        fseeko(this->m_file, offset, SEEK_SET);
     }
 
     void File::close() {
@@ -142,10 +142,10 @@ namespace pl::hlp::fs {
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
@@ -156,7 +156,7 @@ namespace pl::hlp::fs {
     void File::setSize(u64 size) {
         if (!isValid()) return;
 
-        auto result = ftruncate64(fileno(this->m_file), size);
+        auto result = ftruncate(fileno(this->m_file), size);
         hlp::unused(result);
     }
 
