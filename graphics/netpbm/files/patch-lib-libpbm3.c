--- lib/libpbm3.c       Fri Oct  1 08:56:33 2004
+++ lib/libpbm3.c.patch Mon Nov 15 15:24:59 2004
@@ -80,6 +80,8 @@

     di const zero64 = 0;        /* to clear with PXOR */

+    int col;
+
     for (col =0; col < cols-7; col += 8)
         packedBits[col/8]
           = bitreverse [ ~ (unsigned char) __builtin_ia32_pmovmskb (
