--- bfd/ecoff.c.orig	2013-03-11 12:42:03.000000000 +0100
+++ bfd/ecoff.c	2013-03-11 12:44:29.000000000 +0100
@@ -1888,7 +1888,7 @@
   ret = (bfd_coff_filhsz (abfd)
 	 + bfd_coff_aoutsz (abfd)
 	 + c * bfd_coff_scnhsz (abfd));
-  return BFD_ALIGN (ret, 16);
+  return (int)BFD_ALIGN (ret, 16);
 }
 
 /* Get the contents of a section.  */
