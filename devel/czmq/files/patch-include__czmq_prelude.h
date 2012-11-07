--- ./include/czmq_prelude.h.orig	2012-10-27 11:18:30.000000000 +0200
+++ ./include/czmq_prelude.h	2012-11-07 09:11:26.233823253 +0100
@@ -279,7 +279,7 @@
 #   include <sys/wait.h>
 #   include <sys/uio.h>                 //  This is required to make CZMQ compile with libzmq/3.x
 #   include <netinet/in.h>              //  Must come before arpa/inet.h
-#   include <uuid/uuid.h>
+#   include <uuid.h>
 #   if (!defined (__UTYPE_ANDROID)) && (!defined (__UTYPE_IBMAIX)) && (!defined (__UTYPE_HPUX)) && (!defined (__UTYPE_SUNOS))
 #       include <ifaddrs.h>
 #   endif
