# Elf_ doesn't exist, use Elf32_ or Elf64_
#
--- src/util/build_id.c.orig	2017-12-21 17:31:22 UTC
+++ src/util/build_id.c
@@ -34,7 +34,11 @@
 #endif
 
 #ifndef ElfW
-#define ElfW(type) Elf_##type
+#ifdef __LP64__
+#define ElfW(type) Elf64_##type
+#else
+#define ElfW(type) Elf32_##type
+#endif
 #endif
 
 #define ALIGN(val, align)      (((val) + (align) - 1) & ~((align) - 1))
