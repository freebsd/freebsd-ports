--- encode_rs_8.c.orig	2019-02-06 10:40:06 UTC
+++ encode_rs_8.c
@@ -3,6 +3,7 @@
  * May be used under the terms of the GNU Lesser General Public License (LGPL)
  */
 #include <string.h>
+#include <sys/types.h>
 #include "fixed.h"
 #ifdef __VEC__
 #include <sys/sysctl.h>
@@ -36,10 +37,16 @@ void encode_rs_8(data_t *data, data_t *parity,int pad)
     }
 #elif __VEC__
     /* Ask the OS if we have Altivec support */
+#ifdef __APPLE__
     int selectors[2] = { CTL_HW, HW_VECTORUNIT };
+#endif
     int hasVectorUnit = 0;
     size_t length = sizeof(hasVectorUnit);
+#ifdef __APPLE__
     int error = sysctl(selectors, 2, &hasVectorUnit, &length, NULL, 0);
+#elif __FreeBSD__
+    int error = sysctlbyname("hw.altivec", &hasVectorUnit, &length, NULL, 0);
+#endif
     if(0 == error && hasVectorUnit)
       cpu_mode = ALTIVEC;
     else
