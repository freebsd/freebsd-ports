--- bfd/elfxx-mips.c.orig	2005-05-28 22:58:29.000000000 +0100
+++ bfd/elfxx-mips.c	2006-05-09 02:55:36.000000000 +0100
@@ -4669,6 +4669,9 @@
     case E_MIPS_MACH_SB1:
       return bfd_mach_mips_sb1;
 
+    case E_MIPS_MACH_ALLEGREX:
+      return bfd_mach_mips_allegrex;
+
     default:
       switch (flags & EF_MIPS_ARCH)
 	{
@@ -7941,6 +7944,10 @@
       val = E_MIPS_ARCH_64 | E_MIPS_MACH_SB1;
       break;
 
+    case bfd_mach_mips_allegrex:
+      val = E_MIPS_ARCH_2 | E_MIPS_MACH_ALLEGREX;
+      break;
+
     case bfd_mach_mipsisa32:
       val = E_MIPS_ARCH_32;
       break;
@@ -8422,6 +8429,8 @@
   if (dynobj != NULL && force_local && h->root.type != STT_TLS)
     {
       got = mips_elf_got_section (dynobj, FALSE);
+      if (got)
+        {
       g = mips_elf_section_data (got)->u.got_info;
 
       if (g->next)
@@ -8472,6 +8481,7 @@
 	  g->global_gotno--;
 	}
     }
+   }
 
   _bfd_elf_link_hash_hide_symbol (info, &h->root, force_local);
 }
@@ -9641,6 +9651,7 @@
   /* MIPS II extensions.  */
   { bfd_mach_mips4000, bfd_mach_mips6000 },
   { bfd_mach_mipsisa32, bfd_mach_mips6000 },
+  { bfd_mach_mips_allegrex, bfd_mach_mips6000 },
 
   /* MIPS I extensions.  */
   { bfd_mach_mips6000, bfd_mach_mips3000 },
