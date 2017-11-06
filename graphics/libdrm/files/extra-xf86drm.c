Error code 512 is being leaked from kernel space. While it should be
converted to either EINTR or EAGAIN in the kernel. Teach libdrm to do this
for now. Newer kernel modules will have this fixed included.

dragonfly fixed this issue in,
http://gitweb.dragonflybsd.org/dragonfly.git/commit/b922632f623ee2cc2c1346bb3a6894a7756676aa
which has been included since the 4.4 release.

--- xf86drm.c.orig	2017-01-30 13:59:15.919081000 +0100
+++ xf86drm.c
@@ -197,7 +197,7 @@ drmIoctl(int fd, unsigned long request, 
 
     do {
         ret = ioctl(fd, request, arg);
-    } while (ret == -1 && (errno == EINTR || errno == EAGAIN));
+    } while (ret == -1 && (errno == EINTR || errno == EAGAIN || errno == 512));
     return ret;
 }
 
