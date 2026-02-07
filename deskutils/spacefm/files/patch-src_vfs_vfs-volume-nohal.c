--- src/vfs/vfs-volume-nohal.c.orig	2023-02-20 22:04:57 UTC
+++ src/vfs/vfs-volume-nohal.c
@@ -35,8 +35,8 @@
 #include <sys/wait.h>
 
 #include <signal.h>  // kill
-#include <linux/kdev_t.h>  // MAJOR MINOR
-#include <sys/sysmacros.h> // needed for dev_t
+//#include <linux/kdev_t.h>  // MAJOR MINOR
+//#include <sys/sysmacros.h> // needed for dev_t
 
 #ifdef HAVE_STATVFS
 #include <sys/statvfs.h>
@@ -1000,6 +1000,7 @@ void info_device_properties( device_t *device )
 
 gchar* info_mount_points( device_t *device )
 {
+#if 0
     gchar *contents;
     gchar **lines;
     GError *error;
@@ -1137,6 +1138,10 @@ gchar* info_mount_points( device_t *device )
     }
     else
         return NULL;
+
+#else
+    return NULL;
+#endif
 }
 
 void info_partition_table( device_t *device )
@@ -1489,9 +1494,11 @@ char* device_show_info( device_t *device )
     
     line[i++] = g_strdup_printf("Showing information for %s\n", device->devnode );
     line[i++] = g_strdup_printf("  native-path:                 %s\n", device->native_path );
+#if 0
     line[i++] = g_strdup_printf("  device:                      %u:%u\n",
                                                 (unsigned int)MAJOR( device->devnum ),
                                                 (unsigned int)MINOR( device->devnum ) );
+#endif
     line[i++] = g_strdup_printf("  device-file:                 %s\n", device->devnode );
     line[i++] = g_strdup_printf("    presentation:              %s\n", device->devnode );
     if ( device->device_by_id )
@@ -1945,11 +1952,13 @@ void parse_mounts( gboolean report )
                 if ( volume = vfs_volume_read_by_mount( devnum,
                                                 devmount->mount_points ) )
                 {
+#if 0
                     printf( "special mount changed: %s (%u:%u) on %s\n",
                                         volume->device_file,
                                         (unsigned int)MAJOR( volume->devnum ),
                                         (unsigned int)MINOR( volume->devnum ),
                                         devmount->mount_points );
+#endif
                     vfs_volume_device_added( volume, FALSE ); //frees volume if needed
                 }
                 else
@@ -2465,8 +2474,12 @@ void vfs_volume_set_info( VFSVolume* volume )
         disp_fstype = g_strdup( volume->fs_type );// g_strdup_printf( "-%s", volume->fs_type );
     else
         disp_fstype = g_strdup( "" );
+#if 0
     disp_devnum = g_strdup_printf( "%u:%u", (unsigned int)MAJOR( volume->devnum ),
                                             (unsigned int)MINOR( volume->devnum ) );
+#else
+    disp_devnum = g_strdup_printf( "" );
+#endif
  
     char* fmt = xset_get_s( "dev_dispname" );
     if ( !fmt )
@@ -3652,6 +3665,7 @@ gboolean vfs_volume_is_automount( VFSVolume* vol )
 
 char* vfs_volume_device_info( VFSVolume* vol )
 {
+#if 0
     struct udev_device* udevice = udev_device_new_from_devnum( udev, 'b',
                                                                vol->devnum );
     if ( udevice == NULL )
@@ -3671,6 +3685,9 @@ char* vfs_volume_device_info( VFSVolume* vol )
     device_free( device );
     udev_device_unref( udevice );
     return info;
+#else
+    return g_strdup_printf( _("( no udev device )") );
+#endif
 }
 
 char* vfs_volume_device_mount_cmd( VFSVolume* vol, const char* options,
@@ -4203,6 +4220,7 @@ static void vfs_volume_device_added( VFSVolume* volume
 
 static gboolean vfs_volume_nonblock_removed( dev_t devnum )
 {
+#if 0
     GList* l;
     VFSVolume* volume;
     
@@ -4226,6 +4244,7 @@ static gboolean vfs_volume_nonblock_removed( dev_t dev
             return TRUE;
         }
     }
+#endif
     return FALSE;
 }
 
