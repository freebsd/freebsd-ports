--- gdb/corelow.c.orig	2017-07-29 11:06:52 UTC
+++ gdb/corelow.c
@@ -517,7 +517,7 @@ get_core_register_section (struct regcache *regcache,
   bool variable_size_section = (regset != NULL
 				&& regset->flags & REGSET_VARIABLE_SIZE);
 
-  thread_section_name section_name (name, regcache->ptid ());
+  thread_section_name section_name (name, regcache_get_ptid (regcache));
 
   section = bfd_get_section_by_name (core_bfd, section_name.c_str ());
   if (! section)
