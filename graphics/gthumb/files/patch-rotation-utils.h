--- src/rotation-utils.h.orig	Sat Dec 24 14:08:28 2005
+++ src/rotation-utils.h	Sun Dec  3 16:39:14 2006
@@ -54,6 +54,7 @@
 
 void			update_orientation_field       (const char      *filename, 
 							RotationData    *rot_data);
+void			reset_orientation_field		(const char	*path);
 gboolean		swap_fields                    (ExifContent     *content,
 							ExifTag          tag1,
 							ExifTag          tag2);
