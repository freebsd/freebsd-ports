--- folly/experimental/symbolizer/Elf.h.orig	2020-09-03 08:32:48 UTC
+++ folly/experimental/symbolizer/Elf.h
@@ -41,7 +41,7 @@ namespace symbolizer {
 #if defined(ElfW)
 #define FOLLY_ELF_ELFW(name) ElfW(name)
 #elif defined(__FreeBSD__)
-#define FOLLY_ELF_ELFW(...) Elf_##name
+#define FOLLY_ELF_ELFW(name) Elf_##name
 #endif
 
 using ElfAddr = FOLLY_ELF_ELFW(Addr);
