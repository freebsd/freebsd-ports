--- osdep/mb_freebsd.cpp.orig	Tue Jul 10 00:22:07 2001
+++ osdep/mb_freebsd.cpp	Wed Aug 14 01:48:18 2002
@@ -34,6 +34,8 @@
 #include <fcntl.h>
 #include <assert.h>
 
+#include <netinet/in.h>
+
 #include "mb.h"
 #include "diskid.h"
 #include "config.h"
