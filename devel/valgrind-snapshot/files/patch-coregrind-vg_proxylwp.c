--- coregrind/vg_proxylwp.c.orig	Thu Dec  9 20:02:58 2004
+++ coregrind/vg_proxylwp.c	Thu Dec  9 20:03:16 2004
@@ -30,6 +30,7 @@
 
 
 #include "vg_include.h"
+#include "vg_unsafe.h"
 
 #ifndef UMTX_CONTESTED
 # if __FreeBSD_version < 502120
