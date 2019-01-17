# Elf_ doesn't exist, use Elf32_ or Elf64_
#
--- src/util/build_id.c.orig	2017-12-21 17:31:22 UTC
+++ src/util/build_id.c
@@ -38,6 +38,10 @@
 #define ElfW(type) Elf_##type
 #endif
 
+#if defined(__FreeBSD__) && __FreeBSD__ < 12
+typedef Elf_Note Elf_Nhdr;
+#endif
+
 struct build_id_note {
    ElfW(Nhdr) nhdr;
 
