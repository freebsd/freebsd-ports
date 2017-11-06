# the defintion of ERESTART is behind a check for _KERNEL, but
# defining that causes errno to not be defined. fortunately, there's
# an alternative switch. unfortunately, those differ by platform and
# _WANT_KERNEL_ERRNO is too recent to be part of any release, so just
# define ERESTART if we still don't have it after including errno.h 
#
--- libkms/vmwgfx.c.orig	2017-04-14 23:29:46 UTC
+++ libkms/vmwgfx.c
@@ -30,10 +30,18 @@
 #include "config.h"
 #endif
 
+#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
+#define _WANT_KERNEL_ERRNO
+#elif defined(__DragonFly__)
+#define _KERNEL_STRUCTURES
+#endif
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
 #include "internal.h"
+#ifndef ERESTART
+#define ERESTART (-1)
+#endif
 
 #include "xf86drm.h"
 #include "libdrm_macros.h"
