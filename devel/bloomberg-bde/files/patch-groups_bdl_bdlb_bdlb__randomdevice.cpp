--- groups/bdl/bdlb/bdlb_randomdevice.cpp.orig	2023-08-03 19:36:39 UTC
+++ groups/bdl/bdlb/bdlb_randomdevice.cpp
@@ -11,6 +11,7 @@ BSLS_IDENT_RCSID(bdlb_sysrandom_cpp,"$Id$ $CSID$")
  || defined(BSLS_PLATFORM_OS_SUNOS)                                           \
  || defined(BSLS_PLATFORM_OS_SOLARIS)                                         \
  || defined(BSLS_PLATFORM_OS_DARWIN)                                          \
+ || defined(BSLS_PLATFORM_OS_FREEBSD)                                         \
  || defined(BSLS_PLATFORM_OS_AIX)
 #define BDLB_USE_DEV_RANDOM
 #include <unistd.h>
