--- chmlib-0.35/chm_lib.c.orig	Thu Jun 30 19:24:09 2005
+++ chmlib-0.35/chm_lib.c	Tue Aug  9 20:22:47 2005
@@ -160,7 +160,7 @@
 /* Sparc        */
 /* MIPS         */
 /* PPC          */
-#elif __i386__ || __sun || __sgi || __ppc__ || __x86_64__
+#elif __i386__ || __sun || __sgi || __ppc__ || __x86_64__ || __ia64__ || __alpha__ || __sparc64__
 typedef unsigned char           UChar;
 typedef short                   Int16;
 typedef unsigned short          UInt16;
