--- raop_play/aexcl_lib.h~	Thu Jul 28 04:43:17 2005
+++ raop_play/aexcl_lib.h	Fri Aug 12 09:28:23 2005
@@ -1,5 +1,5 @@
 #include <stdio.h>
-#include <asm/types.h>
+#include <sys/types.h>
 #include <sys/time.h>
 #include <time.h>
 #include <stdlib.h>
@@ -35,6 +35,9 @@
 #define END_C_DECLS
 #endif
 
+#define __u8 u_int8_t
+#define __u16 u_int16_t
+#define __u32 u_int32_t
 
 BEGIN_C_DECLS
 
