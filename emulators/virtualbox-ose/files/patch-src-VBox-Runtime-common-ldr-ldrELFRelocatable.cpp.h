--- src/VBox/Runtime/common/ldr/ldrELFRelocatable.cpp.h.orig	2015-03-02 10:10:00.000000000 -0500
+++ src/VBox/Runtime/common/ldr/ldrELFRelocatable.cpp.h	2015-03-12 15:59:41.932947000 -0400
@@ -249,7 +249,7 @@
         }
         else
         {
-            AssertReturn(pSym->st_shndx < pModElf->cSyms || pSym->st_shndx == SHN_ABS, ("%#x\n", pSym->st_shndx));
+            AssertMsg(pSym->st_shndx < pModElf->cSyms || pSym->st_shndx == SHN_ABS, ("%#x\n", pSym->st_shndx));
 #if   ELF_MODE == 64
             SymValue = pSym->st_value;
 #endif
