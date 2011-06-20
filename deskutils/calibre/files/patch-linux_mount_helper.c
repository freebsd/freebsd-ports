--- src/calibre/devices/linux_mount_helper.c.orig	2011-06-19 09:35:30.000000000 -0500
+++ src/calibre/devices/linux_mount_helper.c	2011-06-14 16:48:50.000000000 -0500
@@ -65,14 +65,24 @@
     snprintf(uids, 100, "%d", getuid());
     snprintf(gids, 100, "%d", getgid());
 #else
+#ifdef __FreeBSD__
+    snprintf(options, 1000, "rw,noexec,nosuid,sync,-u=%d,-g=%d",getuid(),getgid());
+#else
     snprintf(options, 1000, "rw,noexec,nosuid,sync,nodev,quiet,shortname=mixed,uid=%d,gid=%d,umask=077,fmask=0177,dmask=0077,utf8,iocharset=iso8859-1", getuid(), getgid());
 #endif
+#endif
+
     ensure_root();
+
 #ifdef __NetBSD__
     execlp("mount_msdos", "mount_msdos", "-u", uids, "-g", gids, "-o", options, dev, mp, NULL);
 #else
+#ifdef __FreeBSD__
+    execlp("mount", "mount", "-t", "msdosfs", "-o", options, dev, mp, NULL);
+#else
     execlp("mount", "mount", "-t", "auto", "-o", options, dev, mp, NULL);
 #endif
+#endif
     errsv = errno;
     fprintf(stderr, "Failed to mount with error: %s\n", strerror(errsv));
     return EXIT_FAILURE;
@@ -92,8 +102,12 @@
 #ifdef __NetBSD__
         execlp("eject", "eject", dev, NULL);
 #else
+#ifdef __FreeBSD__
+	execlp("umount", "umount", dev, NULL);
+#else
         execlp("eject", "eject", "-s", dev, NULL);
 #endif
+#endif
         /* execlp failed */
         errsv = errno;
         fprintf(stderr, "Failed to eject with error: %s\n", strerror(errsv));
@@ -121,7 +135,11 @@
 
     if (pid == 0) { /* Child process */
         ensure_root();
+#ifdef __FreeBSD__
+        execlp("umount", "umount", mp, NULL);
+#else
         execlp("umount", "umount", "-l", mp, NULL);
+#endif
         /* execlp failed */
         errsv = errno;
         fprintf(stderr, "Failed to umount with error: %s\n", strerror(errsv));
