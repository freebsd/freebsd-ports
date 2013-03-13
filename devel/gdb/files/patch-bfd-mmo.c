--- bfd/mmo.c.orig	2013-03-11 12:17:57.000000000 +0100
+++ bfd/mmo.c	2013-03-11 12:17:21.000000000 +0100
@@ -663,7 +663,7 @@
 	return NULL;
 
       if (! sec->user_set_vma)
-	bfd_set_section_vma (abfd, sec, vma);
+	(void)bfd_set_section_vma (abfd, sec, vma);
       if (! bfd_set_section_flags (abfd, sec,
 				   bfd_get_section_flags (abfd, sec)
 				   | SEC_CODE | SEC_LOAD | SEC_ALLOC))
@@ -677,7 +677,7 @@
 	return NULL;
 
       if (! sec->user_set_vma)
-	bfd_set_section_vma (abfd, sec, vma);
+	(void)bfd_set_section_vma (abfd, sec, vma);
       if (! bfd_set_section_flags (abfd, sec,
 				   bfd_get_section_flags (abfd, sec)
 				   | SEC_LOAD | SEC_ALLOC))
@@ -693,7 +693,7 @@
   sprintf (sec_name, ".MMIX.sec.%d", abfd->tdata.mmo_data->sec_no++);
   sec = mmo_make_section (abfd, sec_name);
   if (! sec->user_set_vma)
-    bfd_set_section_vma (abfd, sec, vma);
+    (void)bfd_set_section_vma (abfd, sec, vma);
 
   if (! bfd_set_section_flags (abfd, sec,
 			       bfd_get_section_flags (abfd, sec)
