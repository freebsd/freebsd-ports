--- xxHash-wrapper/xxHash-0.7.2/xxh3.h.orig	2020-06-13 11:40:25 UTC
+++ xxHash-wrapper/xxHash-0.7.2/xxh3.h
@@ -159,8 +159,10 @@
 /* VSX stuff. It's a lot because VSX support is mediocre across compilers and
  * there is a lot of mischief with endianness. */
 #if XXH_VECTOR == XXH_VSX
-#  include <altivec.h>
+#  undef bool
 #  undef vector
+#  include <altivec.h>
+#  define bool _Bool
 typedef __vector unsigned long long U64x2;
 typedef __vector unsigned char U8x16;
 typedef __vector unsigned U32x4;
