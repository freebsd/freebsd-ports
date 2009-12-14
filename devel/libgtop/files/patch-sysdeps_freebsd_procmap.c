--- sysdeps/freebsd/procmap.c.orig	2009-12-13 18:53:02.827740000 -0500
+++ sysdeps/freebsd/procmap.c	2009-12-13 19:00:04.000000000 -0500
@@ -85,7 +85,9 @@ _glibtop_sysdeps_freebsd_dev_inode (glib
         char tagstr[12];
         struct inode inode;
         struct cdev_priv priv;
+#if __FreeBSD_version < 800039
         struct cdev si;
+#endif
 
         *inum = 0;
         *dev = 0;
@@ -111,18 +113,18 @@ _glibtop_sysdeps_freebsd_dev_inode (glib
                 return;
         }
 
-        if (kvm_read (server->machine.kd, (gulong) inode.i_dev, (char *) &si,
-	              sizeof (si)) != sizeof (si) ||
 #if __FreeBSD_version >= 800039
-            kvm_read (server->machine.kd, (gulong)  cdev2priv(&si), (char *) &priv,
+        if (kvm_read (server->machine.kd, (gulong) cdev2priv(inode.i_dev), (char *) &priv,
 		      sizeof (priv))
 #else
+        if (kvm_read (server->machine.kd, (gulong) inode.i_dev, (char *) &si,
+	              sizeof (si)) != sizeof (si) ||
             kvm_read (server->machine.kd, (gulong) si.si_priv, (char *) &priv,
 		      sizeof (priv))
 #endif
 	    != sizeof (priv))
         {
-                glibtop_warn_io_r (server, "kvm_read (si)");
+                glibtop_warn_io_r (server, "kvm_read (priv)");
                 return;
         }
 
