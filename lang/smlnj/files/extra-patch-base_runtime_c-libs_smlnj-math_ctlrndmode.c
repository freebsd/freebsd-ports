--- base/runtime/c-libs/smlnj-math/ctlrndmode.c.orig	2000-06-01 20:34:03.000000000 +0200
+++ base/runtime/c-libs/smlnj-math/ctlrndmode.c	2013-06-18 15:08:01.715990633 +0200
@@ -3,6 +3,19 @@
  * COPYRIGHT (c) 1996 AT&T Research.
  */
 
+ #if defined(OPSYS_FREEBSD)
+ #  if defined(INCLUDE_FREEBSD_I386__TYPES)
+ #    include <sys/cdefs.h>
+ #    include INCLUDE_FREEBSD_I386__TYPES
+ #  endif
+ #  if defined(INCLUDE_FREEBSD_I386_ENDIAN)
+ #    include INCLUDE_FREEBSD_I386_ENDIAN
+ #  endif
+ #  if defined(INCLUDE_FREEBSD_I386_IEEEFP)
+ #    include INCLUDE_FREEBSD_I386_IEEEFP
+ #  endif
+ #endif
+ 
 #include "ml-base.h"
 #include "fp-dep.h"
 #include "ml-objects.h"
