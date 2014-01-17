--- daemon/gvfsbackendgphoto2.c.orig	2012-05-16 02:01:50.000000000 +0800
+++ daemon/gvfsbackendgphoto2.c	2014-01-18 01:43:32.000000000 +0800
@@ -1647,7 +1647,9 @@
       return;
     }
 
+#ifndef HAVE_GPHOTO25
   DEBUG ("  '%s' '%s' '%s'",  info.name, info.path, info.library_filename);
+#endif
   
   /* set port */
   rc = gp_camera_set_port_info (gphoto2_backend->camera, info);
@@ -2590,7 +2592,11 @@
         }
     }
 
+#ifdef HAVE_GPHOTO25
+  rc = gp_camera_folder_put_file (gphoto2_backend->camera, dir, new_name, GP_FILE_TYPE_NORMAL, file_dest, gphoto2_backend->context);
+#else
   rc = gp_camera_folder_put_file (gphoto2_backend->camera, dir, file_dest, gphoto2_backend->context);
+#endif
   if (rc != 0)
     goto out;
 
@@ -3222,14 +3228,18 @@
   if (rc != 0)
     goto out;
 
-  gp_file_set_type (file, GP_FILE_TYPE_NORMAL);
   gp_file_set_name (file, write_handle->name);
   gp_file_set_mtime (file, time (NULL));
   gp_file_set_data_and_size (file, 
                              dup_for_gphoto2 (write_handle->data, write_handle->size), 
                              write_handle->size);
   
+#ifdef HAVE_GPHOTO25
+  rc = gp_camera_folder_put_file (gphoto2_backend->camera, write_handle->dir, write_handle->name, GP_FILE_TYPE_NORMAL, file, gphoto2_backend->context);
+#else
+  gp_file_set_type (file, GP_FILE_TYPE_NORMAL);
   rc = gp_camera_folder_put_file (gphoto2_backend->camera, write_handle->dir, file, gphoto2_backend->context);
+#endif
   if (rc != 0)
     {
       gp_file_unref (file);
