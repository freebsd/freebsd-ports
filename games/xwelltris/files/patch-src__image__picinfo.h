--- src/image/picinfo.h.orig	2003-01-04 11:37:22 UTC
+++ src/image/picinfo.h
@@ -11,8 +11,7 @@
 #include <string.h>
 #include <sys/param.h>
 #include <sys/types.h>
-#ifndef __FreeBSD__                                                            
-#elif ! defined __OpenBSD__
+#if ! defined __OpenBSD__ && ! defined __FreeBSD__ && ! defined __DragonFly__
 #include <malloc.h>
 #endif
 #include <fcntl.h>
