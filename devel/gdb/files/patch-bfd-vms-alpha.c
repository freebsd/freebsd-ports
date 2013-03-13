--- bfd/vms-alpha.c.orig	2013-03-11 10:40:39.000000000 +0100
+++ bfd/vms-alpha.c	2013-03-11 12:31:12.000000000 +0100
@@ -6044,7 +6044,7 @@
                      unsigned char *rec, unsigned int rec_len)
 {
   unsigned int off = sizeof (struct vms_egsd);
-  unsigned int sec_len;
+  unsigned int sec_len = 0;
 
   fprintf (file, _("  %s (len=%u+%u):\n"), name,
            (unsigned)(rec_len - sizeof (struct vms_eobjrec)),
@@ -9118,7 +9118,7 @@
   vms_debug2 ((1, "vms_new_section_hook (%p, [%d]%s)\n",
                abfd, section->index, section->name));
 
-  bfd_set_section_alignment (abfd, section, 0);
+  (void)bfd_set_section_alignment (abfd, section, 0);
 
   vms_debug2 ((7, "%d: %s\n", section->index, section->name));
 
