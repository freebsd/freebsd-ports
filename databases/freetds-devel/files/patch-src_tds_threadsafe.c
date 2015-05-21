--- src/tds/threadsafe.c.orig	2015-02-25 09:00:37 UTC
+++ src/tds/threadsafe.c
@@ -23,6 +23,8 @@
 #include <stdarg.h>
 #include <stdio.h>
 
+#undef HAVE_GETPWUID_R
+
 #if HAVE_UNISTD_H
 #include <unistd.h>
 #endif /* HAVE_UNISTD_H */
