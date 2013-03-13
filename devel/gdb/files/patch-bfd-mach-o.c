--- bfd/mach-o.c.orig	2013-03-07 10:15:55.000000000 +0100
+++ bfd/mach-o.c	2013-03-07 10:16:09.000000000 +0100
@@ -2683,7 +2683,7 @@
 	  s->flags = xlat->macho_sectype | xlat->macho_secattr;
 	  s->align = xlat->sectalign > bfdalign ? xlat->sectalign 
 						: bfdalign;
-	  bfd_set_section_alignment (abfd, sec, s->align);
+	  (void)bfd_set_section_alignment (abfd, sec, s->align);
 	  bfd_flags = bfd_get_section_flags (abfd, sec);
 	  if (bfd_flags == SEC_NO_FLAGS)
 	    bfd_set_section_flags (abfd, sec, xlat->bfd_flags);
