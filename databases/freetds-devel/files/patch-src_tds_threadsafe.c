--- src/tds/threadsafe.c.orig	2015-02-03 16:39:23.431814538 +0600
+++ src/tds/threadsafe.c	2015-02-03 16:39:40.516813065 +0600
@@ -23,6 +23,8 @@
 #include <stdarg.h>
 #include <stdio.h>
 
+#undef HAVE_GETPWUID_R
+
 #if HAVE_UNISTD_H
 #include <unistd.h>
 #endif /* HAVE_UNISTD_H */
