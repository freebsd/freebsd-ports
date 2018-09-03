--- libubertooth/src/ubertooth_control.h.orig	2018-08-07 22:27:29 UTC
+++ libubertooth/src/ubertooth_control.h
@@ -36,7 +36,7 @@
 #define htole16 EndianU16_NtoL
 #define htole32 EndianU32_NtoL
 #else
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 #include <stdio.h>
