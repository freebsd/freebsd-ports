--- openmp/libomptarget/plugins/amdgpu/impl/system.cpp.orig
+++ openmp/libomptarget/plugins/amdgpu/impl/system.cpp
@@ -35,6 +35,7 @@
 /*
  * Note descriptors.
  */
+ #ifndef __FreeBSD__
 typedef struct {
   uint32_t n_namesz; /* Length of note's name. */
   uint32_t n_descsz; /* Length of note's value. */
@@ -43,6 +44,7 @@
   // then padding, optional
   // then desc, at 4 byte alignment (not 8, despite being elf64)
 } Elf_Note;
+#endif
 
 // The following include file and following structs/enums
 // have been replicated on a per-use basis below. For example,
