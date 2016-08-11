--- alsamixer/volume_mapping.c.orig	2016-03-31 14:37:02 UTC
+++ alsamixer/volume_mapping.c
@@ -37,7 +37,7 @@
 #include <stdbool.h>
 #include "volume_mapping.h"
 
-#ifdef __UCLIBC__
+#ifndef __GLIBC__
 /* 10^x = 10^(log e^x) = (e^x)^log10 = e^(x * log 10) */
 #define exp10(x) (exp((x) * log(10)))
 #endif /* __UCLIBC__ */
