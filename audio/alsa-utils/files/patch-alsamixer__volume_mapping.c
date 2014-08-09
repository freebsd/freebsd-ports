--- alsamixer/volume_mapping.c~
+++ alsamixer/volume_mapping.c
@@ -37,7 +37,7 @@
 #include <stdbool.h>
 #include "volume_mapping.h"
 
-#ifdef __UCLIBC__
+#ifndef __GLIBC__
 /* 10^x = 10^(log e^x) = (e^x)^log10 = e^(x * log 10) */
 #define exp10(x) (exp((x) * log(10)))
 #endif /* __UCLIBC__ */
