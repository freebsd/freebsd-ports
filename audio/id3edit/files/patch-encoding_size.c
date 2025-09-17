--- encoding/size.c.orig	2025-09-17 05:47:49 UTC
+++ encoding/size.c
@@ -5,6 +5,7 @@
 #include <endian.h>
 #endif
 #include <encoding/size.h>
+#include <sys/types.h>
 
 
 unsigned int ID3V2_EncodeSize(unsigned int size)
