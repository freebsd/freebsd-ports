--- src/common/linux/elfutils.cc.orig	2017-07-12 17:53:15 UTC
+++ src/common/linux/elfutils.cc
@@ -35,6 +35,12 @@
 #include "common/linux/linux_libc_support.h"
 #include "common/linux/elfutils-inl.h"
 
+#ifndef ElfW
+#define ElfW(type)	_ElfW (Elf, __ELF_WORD_SIZE, type)
+#define _ElfW(e,w,t)	_ElfW_1 (e, w, _##t)
+#define _ElfW_1(e,w,t)	e##w##t
+#endif
+
 namespace google_breakpad {
 
 namespace {
