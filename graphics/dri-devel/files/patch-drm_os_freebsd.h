Index: programs/Xserver/hw/xfree86/os-support/bsd/drm/kernel/drm_os_freebsd.h
===================================================================
RCS file: /cvsroot/dri/xc/xc/programs/Xserver/hw/xfree86/os-support/bsd/drm/kernel/drm_os_freebsd.h,v
retrieving revision 1.9
retrieving revision 1.10
diff -u -r1.9 -r1.10
--- programs/Xserver/hw/xfree86/os-support/bsd/drm/kernel/drm_os_freebsd.h	29 Sep 2002 23:21:55 -0000	1.9
+++ programs/Xserver/hw/xfree86/os-support/bsd/drm/kernel/drm_os_freebsd.h	14 Oct 2002 23:35:24 -0000	1.10
@@ -142,7 +142,7 @@
 #define DRM_HZ hz
 
 #define DRM_WAIT_ON( ret, queue, timeout, condition )			\
-while (condition) {							\
+while (!condition) {							\
 	ret = tsleep( &(queue), PZERO | PCATCH, "drmwtq", (timeout) );	\
 	if ( ret )							\
 		return ret;						\
