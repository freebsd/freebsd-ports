--- src/netcpu_sysctl.c.orig	2014-06-03 23:37:37 UTC
+++ src/netcpu_sysctl.c
@@ -6,6 +6,8 @@ char   netcpu_sysctl_id[]="\
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
 
 #if HAVE_INTTYPES_H
