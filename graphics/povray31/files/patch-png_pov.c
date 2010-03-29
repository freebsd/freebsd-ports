--- source/png_pov.c.orig	1999-05-01 15:01:24.000000000 +0200
+++ source/png_pov.c	2010-03-29 11:17:58.000000000 +0200
@@ -1445,7 +1445,7 @@
     if (r_info_ptr->valid & PNG_INFO_tRNS)
     {
       for (index = 0; index < r_info_ptr->num_trans; index++)
-        cmap[index].Transmit = 255 - r_info_ptr->trans[index];
+        cmap[index].Transmit = 255 - r_info_ptr->trans_alpha[index];
     }
 
     Image->data.map_lines = (unsigned char **)
@@ -1479,7 +1479,7 @@
     if (r_info_ptr->valid & PNG_INFO_tRNS)
     {
       for (index = 0; index < r_info_ptr->num_trans; index++)
-        cmap[index].Transmit = 255 - r_info_ptr->trans[index];
+        cmap[index].Transmit = 255 - r_info_ptr->trans_alpha[index];
     }
 
     Image->data.map_lines = (unsigned char **)
