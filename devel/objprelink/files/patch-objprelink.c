$FreeBSD$

--- objprelink.c.orig	Tue Dec  4 14:01:10 2001
+++ objprelink.c	Tue Dec  4 14:01:49 2001
@@ -239,12 +239,12 @@
 is_vt_section(bfd *abfd, asection *p)
 {
   const char *name = bfd_section_name(abfd, p);
-  static const char prefix[] = ".gnu.linkonce.d.__vt_";
+  static const char prefix[] = ".gnu.linkonce.d._vt";
   static flagword w = (SEC_ALLOC|SEC_LOAD|SEC_RELOC|SEC_DATA|SEC_LINK_ONCE);
   flagword f = bfd_get_section_flags (abfd, p);
   if (f & w == w)
     if (!strncmp(name, prefix, sizeof(prefix)-1))
-      return name + sizeof(prefix)-6;
+      return name + sizeof(prefix)-4;
   return false;
 }
 
