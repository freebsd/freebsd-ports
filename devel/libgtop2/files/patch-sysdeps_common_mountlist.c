--- sysdeps/common/mountlist.c.orig	Fri Dec 19 12:23:02 2003
+++ sysdeps/common/mountlist.c	Fri Dec 19 12:23:41 2003
@@ -136,7 +136,7 @@
 }
 #endif /* MOUNTED_GETMNTENT1.  */
 
-#if defined (MOUNTED_GETMNTINFO) && !defined (__NetBSD__) && !defined (__OpenBSD__)
+#if defined (MOUNTED_GETMNTINFO) && !defined (__NetBSD__) && !defined (__OpenBSD__) && !defined(__FreeBSD__)
 static char *
 fstype_to_string (t)
      short t;
@@ -354,7 +354,7 @@
 	me = (struct mount_entry *) xmalloc (sizeof (struct mount_entry));
 	me->me_devname = xstrdup (fsp->f_mntfromname);
 	me->me_mountdir = xstrdup (fsp->f_mntonname);
-#if defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 	me->me_type = xstrdup (fsp->f_fstypename);
 #else
 	me->me_type = xstrdup (fstype_to_string (fsp->f_type));
