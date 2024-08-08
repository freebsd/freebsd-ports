--- base/debug/elf_reader.cc.orig	2024-06-18 21:43:17 UTC
+++ base/debug/elf_reader.cc
@@ -50,6 +50,10 @@ constexpr char kGnuNoteName[] = "GNU";
 
 constexpr char kGnuNoteName[] = "GNU";
 
+#ifndef NT_GNU_BUILD_ID
+#define NT_GNU_BUILD_ID 3
+#endif
+
 // Returns a pointer to the header of the ELF binary mapped into memory, or a
 // null pointer if the header is invalid. Here and below |elf_mapped_base| is a
 // pointer to the start of the ELF image.
