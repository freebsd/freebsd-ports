--- hotspot/src/os/bsd/vm/os_bsd.cpp.orig	2014-03-04 02:52:13 UTC
+++ hotspot/src/os/bsd/vm/os_bsd.cpp
@@ -1452,6 +1452,10 @@ void * os::dll_load(const char *filename, char *ebuf, 
   #define EM_X86_64       62              /* AMD x86-64 */
   #endif
 
+  #ifndef EM_AARCH64
+  #define EM_AARCH64     183              /* ARM AARCH64 */
+  #endif
+
   static const arch_t arch_array[]={
     {EM_386,         EM_386,     ELFCLASS32, ELFDATA2LSB, (char*)"IA 32"},
     {EM_486,         EM_386,     ELFCLASS32, ELFDATA2LSB, (char*)"IA 32"},
@@ -1468,7 +1472,8 @@ void * os::dll_load(const char *filename, char *ebuf, 
     {EM_MIPS_RS3_LE, EM_MIPS_RS3_LE, ELFCLASS32, ELFDATA2LSB, (char*)"MIPSel"},
     {EM_MIPS,        EM_MIPS,    ELFCLASS32, ELFDATA2MSB, (char*)"MIPS"},
     {EM_PARISC,      EM_PARISC,  ELFCLASS32, ELFDATA2MSB, (char*)"PARISC"},
-    {EM_68K,         EM_68K,     ELFCLASS32, ELFDATA2MSB, (char*)"M68k"}
+    {EM_68K,         EM_68K,     ELFCLASS32, ELFDATA2MSB, (char*)"M68k"},
+    {EM_AARCH64,     EM_AARCH64, ELFCLASS64, ELFDATA2LSB, (char*)"AARCH64"},
   };
 
   #if  (defined IA32)
@@ -1485,6 +1490,8 @@ void * os::dll_load(const char *filename, char *ebuf, 
     static  Elf32_Half running_arch_code=EM_PPC64;
   #elif  (defined __powerpc__)
     static  Elf32_Half running_arch_code=EM_PPC;
+  #elif  (defined AARCH64)
+    static  Elf32_Half running_arch_code=EM_AARCH64;
   #elif  (defined ARM)
     static  Elf32_Half running_arch_code=EM_ARM;
   #elif  (defined S390)
@@ -1501,7 +1508,7 @@ void * os::dll_load(const char *filename, char *ebuf, 
     static  Elf32_Half running_arch_code=EM_68K;
   #else
     #error Method os::dll_load requires that one of following is defined:\
-         IA32, AMD64, IA64, __sparc, __powerpc__, ARM, S390, ALPHA, MIPS, MIPSEL, PARISC, M68K
+         AARCH64, IA32, AMD64, IA64, __sparc, __powerpc__, ARM, S390, ALPHA, MIPS, MIPSEL, PARISC, M68K
   #endif
 
   // Identify compatability class for VM's architecture and library's architecture
