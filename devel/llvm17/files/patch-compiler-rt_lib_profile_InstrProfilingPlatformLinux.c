--- compiler-rt/lib/profile/InstrProfilingPlatformLinux.c.orig
+++ compiler-rt/lib/profile/InstrProfilingPlatformLinux.c
@@ -17,6 +17,10 @@
 #include "InstrProfiling.h"
 #include "InstrProfilingInternal.h"
 
+#if !defined(ElfW)
+#define ElfW(type) Elf_##type
+#endif
+
 #define PROF_DATA_START INSTR_PROF_SECT_START(INSTR_PROF_DATA_COMMON)
 #define PROF_DATA_STOP INSTR_PROF_SECT_STOP(INSTR_PROF_DATA_COMMON)
 #define PROF_NAME_START INSTR_PROF_SECT_START(INSTR_PROF_NAME_COMMON)
