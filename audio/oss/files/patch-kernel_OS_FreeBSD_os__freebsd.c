--- kernel/OS/FreeBSD/os_freebsd.c.orig	2019-03-06 07:52:21 UTC
+++ kernel/OS/FreeBSD/os_freebsd.c
@@ -920,15 +920,9 @@ oss_poll (struct cdev *bsd_dev, int events, struct thr
   return ev.revents;
 }
 
-#if defined(D_VERSION_03) && (D_VERSION == D_VERSION_03)
 static int
 oss_mmap (struct cdev *bsd_dev, vm_ooffset_t offset, vm_paddr_t * paddr,
 	  int nprot, vm_memattr_t *memattr)
-#else
-static int
-oss_mmap (struct cdev *bsd_dev, vm_offset_t offset, vm_paddr_t * paddr,
-	  int nprot)
-#endif
 {
   int retval;
   int dev;
