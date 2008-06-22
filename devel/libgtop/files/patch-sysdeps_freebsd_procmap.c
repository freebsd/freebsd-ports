--- sysdeps/freebsd/procmap.c.orig	2008-06-21 01:58:25.000000000 +0200
+++ sysdeps/freebsd/procmap.c	2008-06-21 01:58:30.000000000 +0200
@@ -103,8 +103,14 @@
 
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
