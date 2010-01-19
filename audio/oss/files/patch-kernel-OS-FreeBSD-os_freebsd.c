--- kernel/OS/FreeBSD/os_freebsd.c.orig	2009-11-13 10:20:53.000000000 -0500
+++ kernel/OS/FreeBSD/os_freebsd.c	2010-01-19 12:58:43.000000000 -0500
@@ -902,9 +902,15 @@
   return ev.revents;
 }
 
+#if defined(D_VERSION_03) && (D_VERSION == D_VERSION_03)
+static int
+oss_mmap (struct cdev *bsd_dev, vm_ooffset_t offset, vm_paddr_t * paddr,
+	  int nprot, vm_memattr_t *memattr)
+#else
 static int
 oss_mmap (struct cdev *bsd_dev, vm_offset_t offset, vm_paddr_t * paddr,
 	  int nprot)
+#endif
 {
   int retval;
   int dev;
