--- base/debug/elf_reader.cc.orig	2021-07-15 19:13:29 UTC
+++ base/debug/elf_reader.cc
@@ -38,7 +38,9 @@ using Nhdr = Elf64_Nhdr;
 using Word = Elf64_Word;
 #endif
 
+#if !defined(OS_BSD)
 constexpr char kGnuNoteName[] = "GNU";
+#endif
 
 // Returns a pointer to the header of the ELF binary mapped into memory, or a
 // null pointer if the header is invalid. Here and below |elf_mapped_base| is a
@@ -75,6 +77,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
     bool found = false;
     while (current_section < section_end) {
       current_note = reinterpret_cast<const Nhdr*>(current_section);
+#if !defined(OS_BSD)
       if (current_note->n_type == NT_GNU_BUILD_ID) {
         StringPiece note_name(current_section + sizeof(Nhdr),
                               current_note->n_namesz);
@@ -84,6 +87,7 @@ size_t ReadElfBuildId(const void* elf_mapped_base,
           break;
         }
       }
+#endif
 
       size_t section_size = bits::AlignUp(current_note->n_namesz, 4) +
                             bits::AlignUp(current_note->n_descsz, 4) +
