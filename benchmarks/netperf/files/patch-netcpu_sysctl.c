--- src/netcpu_sysctl.c.orig	2014-06-04 01:37:37.000000000 +0200
+++ src/netcpu_sysctl.c	2015-10-19 16:05:51.583777000 +0200
@@ -6,6 +6,8 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
 
 #if HAVE_INTTYPES_H
