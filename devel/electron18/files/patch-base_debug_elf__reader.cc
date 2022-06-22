--- base/debug/elf_reader.cc.orig	2022-05-11 07:16:46 UTC
+++ base/debug/elf_reader.cc
@@ -76,6 +76,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
     bool found = false;
     while (current_section < section_end) {
       current_note = reinterpret_cast<const Nhdr*>(current_section);
+#if !defined(OS_BSD)
       if (current_note->n_type == NT_GNU_BUILD_ID) {
         StringPiece note_name(current_section + sizeof(Nhdr),
                               current_note->n_namesz);
@@ -85,6 +86,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
           break;
         }
       }
+#endif
 
       size_t section_size = bits::AlignUp(current_note->n_namesz, 4) +
                             bits::AlignUp(current_note->n_descsz, 4) +
