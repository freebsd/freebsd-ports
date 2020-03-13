--- base/debug/elf_reader.cc.orig	2019-12-12 12:38:58 UTC
+++ base/debug/elf_reader.cc
@@ -83,6 +83,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
         reinterpret_cast<const Nhdr*>(elf_base + header.p_vaddr);
     bool found = false;
     while (current_note < section_end) {
+#if !defined(OS_BSD)
       if (current_note->n_type == NT_GNU_BUILD_ID) {
         const char* note_name =
             reinterpret_cast<const char*>(current_note) + sizeof(Nhdr);
@@ -92,6 +93,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
           break;
         }
       }
+#endif
 
       current_note = reinterpret_cast<const Nhdr*>(
           reinterpret_cast<const char*>(current_note) + sizeof(Nhdr) +
