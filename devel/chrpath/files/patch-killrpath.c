--- killrpath.c.orig	2025-02-22 12:25:43 UTC
+++ killrpath.c
@@ -37,9 +37,9 @@
 killrpath(const char *filename)
 {
    int fd;
-   Elf_Ehdr ehdr;
+   absElf_Ehdr ehdr;
    int i;
-   Elf_Phdr phdr;
+   absElf_Phdr phdr;
    void *dyns;
    int dynpos;
 
