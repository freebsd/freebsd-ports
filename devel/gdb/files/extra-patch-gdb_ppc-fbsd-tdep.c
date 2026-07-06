--- gdb/ppc-fbsd-tdep.c.orig	2026-06-04 12:15:06.422114475 +0200
+++ gdb/ppc-fbsd-tdep.c	2026-06-04 12:15:07.853463132 +0200
@@ -322,9 +322,18 @@
   /* Generic FreeBSD support. */
   fbsd_init_abi (info, gdbarch);
 
-  /* FreeBSD doesn't support the 128-bit `long double' from the psABI.  */
-  set_gdbarch_long_double_bit (gdbarch, 64);
-  set_gdbarch_long_double_format (gdbarch, floatformats_ieee_double);
+  /* powerpc64le switched long double to IEEE 754 binary128 in FreeBSD 16;
+     other powerpc variants keep the 64-bit `long double'.  */
+  if (tdep->wordsize == 8 && info.byte_order == BFD_ENDIAN_LITTLE)
+    {
+      set_gdbarch_long_double_bit (gdbarch, 128);
+      set_gdbarch_long_double_format (gdbarch, floatformats_ieee_quad);
+    }
+  else
+    {
+      set_gdbarch_long_double_bit (gdbarch, 64);
+      set_gdbarch_long_double_format (gdbarch, floatformats_ieee_double);
+    }
 
   if (tdep->wordsize == 4)
     {
