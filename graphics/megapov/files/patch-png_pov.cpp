--- source/png_pov.cpp.orig	2005-08-23 20:20:33.000000000 +0100
+++ source/png_pov.cpp	2010-11-24 10:15:11.000000000 +0000
@@ -1437,7 +1437,7 @@
 		if(r_info_ptr->valid & PNG_INFO_tRNS)
 		{
 			for (index = 0; index < r_info_ptr->num_trans; index++)
-				cmap[index].Transmit = 255 - r_info_ptr->trans[index];
+				cmap[index].Transmit = 255 - r_info_ptr->trans_alpha[index];
 		}
 
 		Image->data.map_lines = (unsigned char **)POV_MALLOC(height * sizeof(unsigned char *), "PNG image");
@@ -1470,7 +1470,7 @@
 		if(r_info_ptr->valid & PNG_INFO_tRNS)
 		{
 			for (index = 0; index < r_info_ptr->num_trans; index++)
-				cmap[index].Transmit = 255 - r_info_ptr->trans[index];
+				cmap[index].Transmit = 255 - r_info_ptr->trans_alpha[index];
 		}
 
 		Image->data.map_lines = (unsigned char **)POV_MALLOC(height * sizeof(unsigned char *), "PNG image");
