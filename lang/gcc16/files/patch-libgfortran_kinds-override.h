--- libgfortran/kinds-override.h.orig
+++ libgfortran/kinds-override.h
@@ -30,7 +30,7 @@
 #endif
 
 /* Keep these conditions on one line so grep can filter it out.  */
-#if defined(__powerpc64__)  && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__  && __SIZEOF_LONG_DOUBLE__ == 16
+#if defined(__powerpc64__)  && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__  && __SIZEOF_LONG_DOUBLE__ == 16 && !defined(__LONG_DOUBLE_IEEE128__)
 typedef _Float128 GFC_REAL_17;
 typedef _Complex _Float128 GFC_COMPLEX_17;
 #define HAVE_GFC_REAL_17
