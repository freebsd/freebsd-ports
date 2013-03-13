--- bfd/elf32-microblaze.c.orig	2013-03-07 10:01:47.000000000 +0100
+++ bfd/elf32-microblaze.c	2013-03-07 10:02:54.000000000 +0100
@@ -1741,7 +1741,7 @@
       for (isym = isymbuf; isym < isymend; isym++)
         {
           if (isym->st_shndx == shndx)
-	    isym->st_value =- calc_fixup (isym->st_value, sec);
+	    isym->st_value = -calc_fixup (isym->st_value, sec);
         }
 
       /* Now adjust the global symbols defined in this section.  */
