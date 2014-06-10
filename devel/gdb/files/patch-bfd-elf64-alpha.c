--- bfd/elf64-alpha.c.orig	2013-03-11 10:52:58.000000000 +0100
+++ bfd/elf64-alpha.c	2013-03-11 11:50:24.000000000 +0100
@@ -3585,9 +3585,9 @@
 
   /* Some compilers warn about a Boolean-looking expression being 
      used in a switch.  The explicit cast silences them.  */
-  switch ((int) (!dynamic && !info->link_info->shared))
-    {
-    case 1:
+  {
+    int skip_default = 0;
+    if (!dynamic && !info->link_info->shared)
       {
 	bfd_vma tp_base;
 	bfd_signed_vma disp;
@@ -3605,7 +3605,7 @@
 	    irel[0].r_offset = pos[0] - info->contents;
 	    irel[0].r_info = ELF64_R_INFO (new_symndx, R_ALPHA_TPREL16);
 	    irel[1].r_info = ELF64_R_INFO (0, R_ALPHA_NONE);
-	    break;
+	    skip_default = 1;
 	  }
 	else if (disp >= -(bfd_signed_vma) 0x80000000
 		 && disp < (bfd_signed_vma) 0x7fff8000
@@ -3620,24 +3620,23 @@
 	    irel[0].r_info = ELF64_R_INFO (new_symndx, R_ALPHA_TPRELHI);
 	    irel[1].r_offset = pos[1] - info->contents;
 	    irel[1].r_info = ELF64_R_INFO (new_symndx, R_ALPHA_TPRELLO);
-	    break;
+	    skip_default = 1;
 	  }
       }
-      /* FALLTHRU */
-
-    default:
-      use_gottprel = TRUE;
-
-      insn = (OP_LDQ << 26) | (tlsgd_reg << 21) | (29 << 16);
-      bfd_put_32 (info->abfd, (bfd_vma) insn, pos[0]);
-      bfd_put_32 (info->abfd, (bfd_vma) INSN_UNOP, pos[1]);
-
-      irel[0].r_offset = pos[0] - info->contents;
-      irel[0].r_info = ELF64_R_INFO (new_symndx, R_ALPHA_GOTTPREL);
-      irel[1].r_info = ELF64_R_INFO (0, R_ALPHA_NONE);
-      break;
-    }
+      /* FALLTHRU (default) */
+    if (skip_default != 1 )
+      {
+        use_gottprel = TRUE;
 
+        insn = (OP_LDQ << 26) | (tlsgd_reg << 21) | (29 << 16);
+        bfd_put_32 (info->abfd, (bfd_vma) insn, pos[0]);
+        bfd_put_32 (info->abfd, (bfd_vma) INSN_UNOP, pos[1]);
+
+        irel[0].r_offset = pos[0] - info->contents;
+        irel[0].r_info = ELF64_R_INFO (new_symndx, R_ALPHA_GOTTPREL);
+        irel[1].r_info = ELF64_R_INFO (0, R_ALPHA_NONE);
+      }
+  }
   bfd_put_32 (info->abfd, (bfd_vma) INSN_RDUNIQ, pos[2]);
 
   insn = INSN_ADDQ | (16 << 21) | (0 << 16) | (0 << 0);
