--- bfd/elf32-v850.c.orig	2013-03-11 12:55:48.000000000 +0100
+++ bfd/elf32-v850.c	2013-03-11 12:57:45.000000000 +0100
@@ -2933,7 +2933,7 @@
 
 	  if (alignmoveto < alignto)
 	    {
-	      unsigned int i;
+	      bfd_vma i;
 
 	      align_pad_size = alignto - alignmoveto;
 #ifdef DEBUG_RELAX
