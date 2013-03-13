--- bfd/elf32-hppa.c.orig	2013-03-07 09:56:40.000000000 +0100
+++ bfd/elf32-hppa.c	2013-03-07 09:57:07.000000000 +0100
@@ -2384,7 +2384,7 @@
 	      bfd_size_type mask;
 
 	      if (gotalign > pltalign)
-		bfd_set_section_alignment (dynobj, sec, gotalign);
+		(void)bfd_set_section_alignment (dynobj, sec, gotalign);
 	      mask = ((bfd_size_type) 1 << gotalign) - 1;
 	      sec->size = (sec->size + sizeof (plt_stub) + mask) & ~mask;
 	    }
