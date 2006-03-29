===================================================================
RCS file: /cvsroot/gphoto/libgphoto2/libgphoto2_port/disk/disk.c,v
retrieving revision 1.4
retrieving revision 1.7
diff -u -r1.4 -r1.7
--- libgphoto2_port/disk/disk.c	2005/08/14 14:01:38	1.4
+++ libgphoto2_port/disk/disk.c	2006/02/19 10:48:10	1.7
@@ -33,7 +33,9 @@
 #include <sys/param.h>
 #include <dirent.h>
 #include <string.h>
-#include <mntent.h>
+#ifdef HAVE_MNTENT_H
+# include <mntent.h>
+#endif
 
 #ifdef HAVE_HAL
 #include <hal/libhal.h>
@@ -172,10 +174,11 @@
         }
 
 	libhal_free_string_array (volumes);
-	libhal_ctx_free(ctx);
-
-	dbus_connection_unref(dbus_connection);
+	libhal_ctx_free (ctx);
+	dbus_connection_disconnect (dbus_connection);
+	dbus_connection_unref (dbus_connection);
 #else
+# ifdef HAVE_MNTENT_H
 	FILE *mnt;
 	struct mntent *mntent;
 	char	path[1024];
@@ -226,7 +229,13 @@
 		CHECK (gp_port_info_list_append (list, info));
 	}
 	endmntent(mnt);
+# endif
 #endif
+	/* generic disk:/xxx/ matcher */
+	info.type = GP_PORT_DISK;
+	memset (info.name, 0, sizeof(info.name));
+	snprintf (info.path, sizeof(info.path), "^disk:");
+	CHECK (gp_port_info_list_append (list, info));
 	return GP_OK;
 }
 
