--- sysdeps/freebsd/procmap.c.orig	2008-04-21 14:58:26.000000000 -0400
+++ sysdeps/freebsd/procmap.c	2008-08-02 15:06:46.000000000 -0400
@@ -41,7 +41,17 @@
 #define _KERNEL
 #include <sys/pipe.h>
 #include <sys/conf.h>
+#undef _KERNEL
+#if __FreeBSD_version >= 800038
+#define _WANT_FILE
 #include <sys/file.h>
+#undef _WANT_FILE
+#else
+#define _KERNEL
+#include <sys/file.h>
+#undef _KERNEL
+#endif
+#define _KERNEL
 #include <sys/mount.h>
 #include <ufs/ufs/quota.h>
 #include <ufs/ufs/inode.h>
@@ -103,8 +113,14 @@ _glibtop_sysdeps_freebsd_dev_inode (glib
 
         if (kvm_read (server->machine.kd, (gulong) inode.i_dev, (char *) &si,
 	              sizeof (si)) != sizeof (si) ||
+#if __FreeBSD_version >= 800039
+            kvm_read (server->machine.kd, (gulong)  cdev2priv(&si), (char *) &priv,
+		      sizeof (priv))
+#else
             kvm_read (server->machine.kd, (gulong) si.si_priv, (char *) &priv,
-		      sizeof (priv)) != sizeof (priv))
+		      sizeof (priv))
+#endif
+	    != sizeof (priv))
         {
                 glibtop_warn_io_r (server, "kvm_read (si)");
                 return;
