--- sysdeps/common/mountlist.c.orig	Mon Dec  1 13:59:28 2003
+++ sysdeps/common/mountlist.c	Mon Dec  1 16:13:15 2003
@@ -127,7 +127,7 @@
 }
 #endif /* MOUNTED_GETMNTENT1.  */
 
-#if defined (MOUNTED_GETMNTINFO) && !defined (__NetBSD__) && !defined (__OpenBSD__)
+#if defined (MOUNTED_GETMNTINFO) && !defined (__NetBSD__) && !defined (__OpenBSD__) && !defined(__FreeBSD__)
 static char *
 fstype_to_string (t)
      short t;
@@ -345,7 +345,7 @@
 	me = (struct mount_entry *) g_malloc (sizeof (struct mount_entry));
 	me->me_devname = g_strdup (fsp->f_mntfromname);
 	me->me_mountdir = g_strdup (fsp->f_mntonname);
-#if defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 	me->me_type = g_strdup (fsp->f_fstypename);
 #else
 	me->me_type = g_strdup (fstype_to_string (fsp->f_type));
