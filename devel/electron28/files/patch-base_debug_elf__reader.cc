--- base/debug/elf_reader.cc.orig	2023-10-19 19:57:58 UTC
+++ base/debug/elf_reader.cc
@@ -78,6 +78,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
     bool found = false;
     while (current_section < section_end) {
       current_note = reinterpret_cast<const Nhdr*>(current_section);
+#if !BUILDFLAG(IS_BSD)
       if (current_note->n_type == NT_GNU_BUILD_ID) {
         StringPiece note_name(current_section + sizeof(Nhdr),
                               current_note->n_namesz);
@@ -87,6 +88,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
           break;
         }
       }
+#endif
 
       size_t section_size = bits::AlignUp(current_note->n_namesz, 4u) +
                             bits::AlignUp(current_note->n_descsz, 4u) +
