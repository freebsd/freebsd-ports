--- src/common/dwarf/elf_reader.cc.orig	2017-07-12 17:53:15 UTC
+++ src/common/dwarf/elf_reader.cc
@@ -56,7 +56,7 @@
 #endif
 
 // Map Linux macros to their Apple equivalents.
-#if __APPLE__
+#if __APPLE__ || __FreeBSD__
 #ifndef __LITTLE_ENDIAN
 #define __LITTLE_ENDIAN __ORDER_LITTLE_ENDIAN__
 #endif  // __LITTLE_ENDIAN
