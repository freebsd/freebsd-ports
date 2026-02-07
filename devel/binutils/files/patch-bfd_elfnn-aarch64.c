--- bfd/elfnn-aarch64.c.orig	2016-11-20 12:04:44.613621000 +0000
+++ bfd/elfnn-aarch64.c	2016-11-20 12:05:01.143334000 +0000
@@ -4369,7 +4369,9 @@
       off = h->got.offset;
       BFD_ASSERT (off != (bfd_vma) - 1);
       if (!WILL_CALL_FINISH_DYNAMIC_SYMBOL (dyn, bfd_link_pic (info), h)
-	  || (bfd_link_pic (info)
+	  || ((bfd_link_pic (info)
+	      || (!bfd_link_relocatable (info)
+		  && (info->export_dynamic || info->dynamic)))
 	      && SYMBOL_REFERENCES_LOCAL (info, h))
 	  || (ELF_ST_VISIBILITY (h->other)
 	      && h->root.type == bfd_link_hash_undefweak))
@@ -8891,6 +8893,14 @@
 			   + h->root.u.def.section->output_section->vma
 			   + h->root.u.def.section->output_offset);
 	}
+      else if (!bfd_link_relocatable (info)
+	    && (info->export_dynamic || info->dynamic)
+	    && SYMBOL_REFERENCES_LOCAL (info, h))
+	{
+	  BFD_ASSERT ((h->got.offset & 1) != 0);
+	  rela.r_info = ELFNN_R_INFO (h->dynindx, AARCH64_R (GLOB_DAT));
+	  rela.r_addend = 0;
+	}
       else
 	{
 do_glob_dat:
