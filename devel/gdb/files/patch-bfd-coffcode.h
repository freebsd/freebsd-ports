--- bfd/coffcode.h.orig	2012-12-18 14:22:56.000000000 +0100
+++ bfd/coffcode.h	2012-12-18 14:23:11.000000000 +0100
@@ -3442,7 +3442,7 @@
 	 incremented in coff_set_section_contents.  This is right for
 	 SVR3.2.  */
       if (strcmp (current->name, _LIB) == 0)
-	bfd_set_section_vma (abfd, current, 0);
+	(void)bfd_set_section_vma (abfd, current, 0);
 #endif
 
 #ifdef ALIGN_SECTIONS_IN_FILE
