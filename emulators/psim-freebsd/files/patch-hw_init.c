diff -r -u sim/ppc/hw_init.c /local2/gcc/ppc/gdb+dejagnu-20011007/sim/ppc/hw_init.c
--- sim/ppc/hw_init.c	Thu May 10 10:48:10 2001
+++ /local2/gcc/ppc/gdb+dejagnu-20011007/sim/ppc/hw_init.c	Fri Oct 12 11:31:51 2001
@@ -350,7 +350,8 @@
 	  ));
 
   /* If there is an .interp section, it means it needs a shared library interpreter.  */
-  if (strcmp(".interp", bfd_get_section_name(abfd, the_section)) == 0)
+  if (current_environment != OPERATING_ENVIRONMENT
+      && strcmp(".interp", bfd_get_section_name(abfd, the_section)) == 0)
     error("Shared libraries are not yet supported.\n");
 
   /* determine the devices access */
