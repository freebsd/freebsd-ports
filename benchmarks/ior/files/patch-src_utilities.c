--- src/utilities.c.orig	2023-01-20 07:46:47 UTC
+++ src/utilities.c
@@ -45,7 +45,7 @@
 #  include <regex.h>
 #  ifdef __sun                    /* SunOS does not support statfs(), instead uses statvfs() */
 #    include <sys/statvfs.h>
-#  elif (defined __APPLE__)
+#  elif (defined __APPLE__) || (defined __FreeBSD__)
 #    include <sys/param.h>
 #    include <sys/mount.h>
 #  else                           /* ! __sun  or __APPLE__ */
