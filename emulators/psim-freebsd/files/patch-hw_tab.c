diff -r -u sim/ppc/hw_htab.c /local2/gcc/ppc/gdb+dejagnu-20011007/sim/ppc/hw_htab.c
--- sim/ppc/hw_htab.c	Thu Apr 15 18:35:09 1999
+++ /local2/gcc/ppc/gdb+dejagnu-20011007/sim/ppc/hw_htab.c	Sun Oct  7 16:16:57 2001
@@ -224,10 +224,12 @@
   }
   *htaborg = htab_ra;
   *htabmask = MASKED32(htab_nr_bytes - 1, 7, 31-6);
+#if 0
   if ((htab_ra & INSERTED32(*htabmask, 7, 15)) != 0) {
     device_error(parent, "htaborg 0x%lx not aligned to htabmask 0x%lx",
 		 (unsigned long)*htaborg, (unsigned long)*htabmask);
   }
+#endif
   DTRACE(htab, ("htab - htaborg=0x%lx htabmask=0x%lx\n",
 		(unsigned long)*htaborg, (unsigned long)*htabmask));
 }
