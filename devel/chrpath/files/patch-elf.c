--- elf.c.orig	2003-12-19 21:07:00.000000000 +0000
+++ elf.c	2009-12-01 20:39:21.000000000 +0000
@@ -55,7 +55,7 @@
    if (ehdr->e_phentsize != sizeof(Elf_Phdr))
    {
      fprintf(stderr, "section size was read as %d, not %d!\n",
-            ehdr->e_phentsize, sizeof(Elf_Phdr));
+            ehdr->e_phentsize, (int)sizeof(Elf_Phdr));
      close(fd);
      return -1;
    }
