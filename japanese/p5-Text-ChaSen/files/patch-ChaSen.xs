--- ChaSen.xs.orig	Wed Aug 18 16:02:16 1999
+++ ChaSen.xs	Tue Aug  1 18:16:03 2000
@@ -12,6 +12,8 @@
 #include "EXTERN.h"
 #include "perl.h"
 #include "XSUB.h"
+#define PERL_POLLUTE 1
+#include "embedvar.h"
 #ifdef __cplusplus
 }
 #endif
