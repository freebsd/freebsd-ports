
$FreeBSD$

--- ELFIImpl.cpp.orig	Wed Dec 18 01:52:15 2002
+++ ELFIImpl.cpp	Wed Dec 18 01:53:31 2002
@@ -100,7 +100,7 @@
 #ifdef _MSC_VER 
     unsigned int buflen = std::_MIN( sizeof( Elf32_Shdr ), (unsigned int)nEntrySize );
 #else
-    unsigned int buflen = std::min( sizeof( Elf32_Shdr ), (unsigned int)nEntrySize );
+    unsigned int buflen = std::min( sizeof( Elf32_Shdr ), (size_t)nEntrySize );
 #endif
 
     for ( int i = 0; i < nNum; ++i ) {
@@ -127,7 +127,7 @@
 #ifdef _MSC_VER 
     int buflen = std::_MIN( sizeof( Elf32_Phdr ), (unsigned int)nEntrySize );
 #else
-    int buflen = std::min( sizeof( Elf32_Phdr ), (unsigned int)nEntrySize );
+    int buflen = std::min( sizeof( Elf32_Phdr ), (size_t)nEntrySize );
 #endif
 
     for ( int i = 0; i < nNum; ++i ) {
