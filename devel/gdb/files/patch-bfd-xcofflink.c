--- bfd/xcofflink.c.orig	2013-03-07 10:16:45.000000000 +0100
+++ bfd/xcofflink.c	2013-03-07 10:19:50.000000000 +0100
@@ -6273,7 +6273,7 @@
       irel = flinfo.section_info[o->target_index].relocs;
       irelend = irel + o->reloc_count;
       rel_hash = flinfo.section_info[o->target_index].rel_hashes;
-      for (; irel < irelend; irel++, rel_hash++, erel += relsz)
+      for (; irel < irelend; irel++, rel_hash++)
 	{
 	  if (*rel_hash != NULL)
 	    {
