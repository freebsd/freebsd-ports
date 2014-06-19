--- src/image/picinfo.h.orig	Sat Jan 31 16:49:01 2004
+++ src/image/picinfo.h	Sat Jan 31 16:49:59 2004
@@ -11,8 +11,7 @@
 #include <string.h>
 #include <sys/param.h>
 #include <sys/types.h>
-#ifndef __FreeBSD__                                                            
-#elif ! defined __OpenBSD__
+#if ! defined __OpenBSD__ && ! defined __FreeBSD__
 #include <malloc.h>
 #endif
 #include <fcntl.h>
