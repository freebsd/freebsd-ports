--- src/powerpc/ffi.c.orig      2013-02-02 17:22:50.000000000 +0100
+++ src/powerpc/ffi.c   2013-02-02 15:30:37.000000000 +0100
@@ -664,9 +664,11 @@
   switch (type)
     {
 #ifndef __NO_FPRS__
+#if FFI_TYPE_LONGDOUBLE != FFI_TYPE_DOUBLE
     case FFI_TYPE_LONGDOUBLE:
       flags |= FLAG_RETURNS_128BITS;
       /* Fall through.  */
+#endif
     case FFI_TYPE_DOUBLE:
       flags |= FLAG_RETURNS_64BITS;
       /* Fall through.  */
