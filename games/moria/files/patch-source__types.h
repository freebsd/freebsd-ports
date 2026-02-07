--- source/types.h.orig	Tue Aug 12 10:04:48 2003
+++ source/types.h	Tue Aug 12 10:06:27 2003
@@ -6,11 +6,20 @@
    not for profit purposes provided that this copyright and statement are
    included in all such copies. */
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+typedef u_int32_t int32u;
+typedef int32_t   int32;
+typedef u_int16_t int16u;
+typedef int16_t   int16;
+typedef u_int8_t  int8u;
+#else
 typedef unsigned long  int32u;
 typedef long	       int32;
 typedef unsigned short int16u;
 typedef short	       int16;
 typedef unsigned char  int8u;
+#endif
 /* some machines will not accept 'signed char' as a type, and some accept it
    but still treat it like an unsigned character, let's just avoid it,
    any variable which can ever hold a negative value must be 16 or 32 bits */
