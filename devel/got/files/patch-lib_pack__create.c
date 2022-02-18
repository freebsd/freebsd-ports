--- lib/pack_create.c.orig	2022-02-18 20:20:09 UTC
+++ lib/pack_create.c
@@ -22,6 +22,7 @@
 #include <sys/stat.h>
 #include <sys/time.h>
 
+#include <endian.h>
 #include <stdint.h>
 #include <imsg.h>
 #include <stdio.h>
