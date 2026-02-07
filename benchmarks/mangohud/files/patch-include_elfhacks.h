--- include/elfhacks.h.orig	2020-08-16 16:54:20 UTC
+++ include/elfhacks.h
@@ -58,6 +58,16 @@ extern "C" {
 # endif
 #endif
 
+#ifndef __ELF_NATIVE_CLASS
+#define __ELF_NATIVE_CLASS __WORDSIZE
+#endif
+
+/* We use this macro to refer to ELF types independent of the native wordsize.
+   `ElfW(TYPE)' is used in place of `Elf32_TYPE' or `Elf64_TYPE'.  */
+#define ElfW(type)	_ElfW (Elf, __ELF_NATIVE_CLASS, type)
+#define _ElfW(e,w,t)	_ElfW_1 (e, w, _##t)
+#define _ElfW_1(e,w,t)	e##w##t
+
 /**
  *  \defgroup elfhacks elfhacks
  *  Elfhacks is a collection of functions that aim for retvieving
