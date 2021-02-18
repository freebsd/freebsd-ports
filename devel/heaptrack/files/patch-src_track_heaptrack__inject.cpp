--- src/track/heaptrack_inject.cpp.orig        2020-06-01 22:47:27 UTC
+++ src/track/heaptrack_inject.cpp
@@ -66,8 +66,18 @@ using Dyn = ElfW(Dyn);
 using Rel = ElfW(Rel);
 using Rela = ElfW(Rela);
 using Sym = ElfW(Sym);
+#if __WORDSIZE == 64
 using Sxword = ElfW(Sxword);
 using Xword = ElfW(Xword);
+#else
+// FreeBSD elf32.h doesn't define Elf32_Sxword or _Xword. This is used in struct
+// elftable, where it's used as a tag value. Our Elf32_Dyn uses Elf32_Sword there,
+// as does the Linux definition (and the standard); the El64_Dyn uses Sxword.
+//
+// Linux elf.h defines Elf32_Sxword as a 64-bit quantity, so let's do that
+using Sxword = int64_t;
+using Xword = uint64_t;
+#endif
 }
 
 void overwrite_symbols() noexcept;
